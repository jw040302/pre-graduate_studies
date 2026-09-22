"""Small introductory node that drives turtle1 forward for three seconds."""

import rclpy
from geometry_msgs.msg import Twist
from rclpy.node import Node


class MoveForward(Node):
    """Publish a constant forward velocity for a fixed duration."""

    def __init__(self):
        """Create the velocity publisher and control timer."""
        super().__init__('move_forward')

        self.velocity_publisher = self.create_publisher(
            Twist,
            '/turtle1/cmd_vel',
            10,
        )

        self.start_time = self.get_clock().now()
        self.timer = self.create_timer(0.1, self.control_turtle)

        self.get_logger().info('海龟开始向前移动')

    def control_turtle(self):
        """Publish forward motion until three seconds have elapsed."""
        current_time = self.get_clock().now()
        elapsed_time = (current_time - self.start_time).nanoseconds / 1e9

        velocity = Twist()

        if elapsed_time < 3.0:
            velocity.linear.x = 1.0
            velocity.angular.z = 0.0
            self.velocity_publisher.publish(velocity)
            return

        self.velocity_publisher.publish(velocity)
        self.get_logger().info('海龟已停止')

        self.timer.cancel()
        rclpy.shutdown()


def main(args=None):
    """Run the move-forward demonstration node."""
    rclpy.init(args=args)

    node = MoveForward()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        if rclpy.ok():
            node.velocity_publisher.publish(Twist())
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == '__main__':
    main()
