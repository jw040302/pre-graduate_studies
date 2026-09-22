"""Closed-loop multi-waypoint patrol controller for turtlesim."""

import math

import rclpy
from geometry_msgs.msg import Twist
from rcl_interfaces.msg import SetParametersResult
from rclpy.node import Node
from std_msgs.msg import String
from std_srvs.srv import Trigger
from turtlesim.msg import Pose


def normalize_angle(angle):
    """Normalize an angle to the range from -pi to pi."""
    return math.atan2(math.sin(angle), math.cos(angle))


class TurtlePatrol(Node):
    """Drive turtle1 around a configurable list of waypoints."""

    def __init__(self):
        """Create publishers, subscriptions, services, and timers."""
        super().__init__('turtle_patrol')

        self.current_pose = None
        self.target_index = 0
        self.completed_laps = 0

        self._declare_parameters()
        self._load_parameters()

        self.velocity_publisher = self.create_publisher(
            Twist,
            '/turtle1/cmd_vel',
            10,
        )
        self.status_publisher = self.create_publisher(
            String,
            '~/status',
            10,
        )
        self.pose_subscription = self.create_subscription(
            Pose,
            '/turtle1/pose',
            self.pose_callback,
            10,
        )

        self.start_service = self.create_service(
            Trigger,
            '~/start',
            self.start_callback,
        )
        self.stop_service = self.create_service(
            Trigger,
            '~/stop',
            self.stop_callback,
        )
        self.reset_service = self.create_service(
            Trigger,
            '~/reset_route',
            self.reset_route_callback,
        )

        self.control_timer = self.create_timer(0.1, self.control_turtle)
        self.report_timer = self.create_timer(1.0, self.report_status)
        self.add_on_set_parameters_callback(self.parameter_callback)

        self._select_current_target()
        state = '自动开始' if self.is_running else '等待启动命令'
        self.get_logger().info(
            f'巡逻节点已启动（{state}），目标点数量：{len(self.waypoints)}'
        )

    def _declare_parameters(self):
        """Declare route and controller parameters."""
        self.declare_parameter('waypoints_x', [2.0, 8.0, 8.0, 2.0])
        self.declare_parameter('waypoints_y', [2.0, 2.0, 8.0, 8.0])
        self.declare_parameter('max_linear_speed', 2.0)
        self.declare_parameter('max_angular_speed', 2.0)
        self.declare_parameter('linear_gain', 1.5)
        self.declare_parameter('angular_gain', 4.0)
        self.declare_parameter('angle_tolerance', 0.2)
        self.declare_parameter('arrival_tolerance', 0.1)
        self.declare_parameter('autostart', True)

    def _load_parameters(self):
        """Read initial parameter values into controller state."""
        waypoint_x = self.get_parameter('waypoints_x').value
        waypoint_y = self.get_parameter('waypoints_y').value
        self.waypoints = self._build_waypoints(waypoint_x, waypoint_y)
        self.max_linear_speed = float(
            self.get_parameter('max_linear_speed').value
        )
        self.max_angular_speed = float(
            self.get_parameter('max_angular_speed').value
        )
        self.linear_gain = float(self.get_parameter('linear_gain').value)
        self.angular_gain = float(self.get_parameter('angular_gain').value)
        self.angle_tolerance = float(
            self.get_parameter('angle_tolerance').value
        )
        self.arrival_tolerance = float(
            self.get_parameter('arrival_tolerance').value
        )
        self.is_running = bool(self.get_parameter('autostart').value)

    @staticmethod
    def _build_waypoints(waypoint_x, waypoint_y):
        """Validate coordinate arrays and combine them into point pairs."""
        if len(waypoint_x) != len(waypoint_y):
            raise ValueError('waypoints_x和waypoints_y的长度必须相同')
        if len(waypoint_x) < 2:
            raise ValueError('巡逻路线至少需要两个目标点')

        waypoints = []
        for x_value, y_value in zip(waypoint_x, waypoint_y):
            x_value = float(x_value)
            y_value = float(y_value)
            if not 0.5 <= x_value <= 10.5:
                raise ValueError('目标点x坐标必须在0.5到10.5之间')
            if not 0.5 <= y_value <= 10.5:
                raise ValueError('目标点y坐标必须在0.5到10.5之间')
            waypoints.append((x_value, y_value))
        return waypoints

    def _select_current_target(self):
        """Copy the selected waypoint into the active target fields."""
        self.target_x, self.target_y = self.waypoints[self.target_index]

    def pose_callback(self, message):
        """Store the most recent turtlesim pose."""
        self.current_pose = message

    def control_turtle(self):
        """Run one iteration of the closed-loop waypoint controller."""
        if self.current_pose is None or not self.is_running:
            return

        difference_x = self.target_x - self.current_pose.x
        difference_y = self.target_y - self.current_pose.y
        distance = math.hypot(difference_x, difference_y)

        if distance < self.arrival_tolerance:
            self._reach_current_target()
            return

        target_angle = math.atan2(difference_y, difference_x)
        angle_error = normalize_angle(
            target_angle - self.current_pose.theta
        )

        velocity = Twist()
        if abs(angle_error) <= self.angle_tolerance:
            velocity.linear.x = min(
                self.linear_gain * distance,
                self.max_linear_speed,
            )

        velocity.angular.z = max(
            -self.max_angular_speed,
            min(
                self.max_angular_speed,
                self.angular_gain * angle_error,
            ),
        )
        self.velocity_publisher.publish(velocity)

    def _reach_current_target(self):
        """Stop briefly, record progress, and select the next waypoint."""
        self.publish_stop()
        self.get_logger().info(
            f'到达目标点 {self.target_index + 1}：'
            f'({self.target_x:.1f}, {self.target_y:.1f})'
        )

        if self.target_index == len(self.waypoints) - 1:
            self.completed_laps += 1
            self.get_logger().info(
                f'完成第 {self.completed_laps} 圈巡逻'
            )

        self.target_index = (self.target_index + 1) % len(self.waypoints)
        self._select_current_target()

    def publish_stop(self):
        """Publish a zero velocity command."""
        self.velocity_publisher.publish(Twist())

    def start_callback(self, request, response):
        """Start or resume patrol when the start service is called."""
        del request
        self.is_running = True
        response.success = True
        response.message = '巡逻已开始或继续'
        self.get_logger().info(response.message)
        self.report_status()
        return response

    def stop_callback(self, request, response):
        """Pause patrol and stop the turtle immediately."""
        del request
        self.is_running = False
        self.publish_stop()
        response.success = True
        response.message = '巡逻已暂停'
        self.get_logger().info(response.message)
        self.report_status()
        return response

    def reset_route_callback(self, request, response):
        """Reset route progress to the first waypoint."""
        del request
        self.publish_stop()
        self.target_index = 0
        self.completed_laps = 0
        self._select_current_target()
        response.success = True
        response.message = '路线进度已重置到第一个目标点'
        self.get_logger().info(response.message)
        self.report_status()
        return response

    def report_status(self):
        """Publish and log a compact human-readable status message."""
        state = '运行中' if self.is_running else '已暂停'
        if self.current_pose is None:
            pose_text = '等待位置数据'
        else:
            pose_text = (
                f'x={self.current_pose.x:.2f}, '
                f'y={self.current_pose.y:.2f}, '
                f'theta={self.current_pose.theta:.2f}'
            )

        status = String()
        status.data = (
            f'状态={state}; 圈数={self.completed_laps}; '
            f'目标={self.target_index + 1}/{len(self.waypoints)}; '
            f'{pose_text}'
        )
        self.status_publisher.publish(status)
        self.get_logger().info(status.data)

    def parameter_callback(self, parameters):
        """Validate and apply supported runtime parameter changes."""
        values = {
            'waypoints_x': [point[0] for point in self.waypoints],
            'waypoints_y': [point[1] for point in self.waypoints],
            'max_linear_speed': self.max_linear_speed,
            'max_angular_speed': self.max_angular_speed,
            'linear_gain': self.linear_gain,
            'angular_gain': self.angular_gain,
            'angle_tolerance': self.angle_tolerance,
            'arrival_tolerance': self.arrival_tolerance,
            'autostart': self.is_running,
        }
        for parameter in parameters:
            if parameter.name in values:
                values[parameter.name] = parameter.value

        try:
            waypoints = self._build_waypoints(
                values['waypoints_x'],
                values['waypoints_y'],
            )
            positive_names = (
                'max_linear_speed',
                'max_angular_speed',
                'linear_gain',
                'angular_gain',
                'angle_tolerance',
                'arrival_tolerance',
            )
            for name in positive_names:
                if values[name] <= 0.0:
                    raise ValueError(f'{name}必须大于0')
            if values['angle_tolerance'] > math.pi:
                raise ValueError('angle_tolerance不能大于pi')
        except (TypeError, ValueError) as error:
            return SetParametersResult(
                successful=False,
                reason=str(error),
            )

        route_changed = any(
            parameter.name in ('waypoints_x', 'waypoints_y')
            for parameter in parameters
        )
        self.waypoints = waypoints
        self.max_linear_speed = float(values['max_linear_speed'])
        self.max_angular_speed = float(values['max_angular_speed'])
        self.linear_gain = float(values['linear_gain'])
        self.angular_gain = float(values['angular_gain'])
        self.angle_tolerance = float(values['angle_tolerance'])
        self.arrival_tolerance = float(values['arrival_tolerance'])
        self.is_running = bool(values['autostart'])

        if route_changed:
            self.target_index = 0
            self.completed_laps = 0
            self._select_current_target()
        if not self.is_running:
            self.publish_stop()

        return SetParametersResult(successful=True)


def main(args=None):
    """Run the turtle patrol node."""
    rclpy.init(args=args)
    node = TurtlePatrol()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        if rclpy.ok():
            node.publish_stop()
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == '__main__':
    main()
