import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node
from turtlesim.action import RotateAbsolute


class RotateTurtleClient(Node):
    def __init__(self):
        super().__init__('rotate_turtle_client')

        self.action_client = ActionClient(
            self,
            RotateAbsolute,
            '/turtle1/rotate_absolute',
        )

    def send_goal(self, theta):
        goal = RotateAbsolute.Goal()
        goal.theta = theta

        self.get_logger().info('正在等待动作服务器……')
        self.action_client.wait_for_server()

        self.get_logger().info(f'发送目标角度：{theta}')

        self.send_goal_future = self.action_client.send_goal_async(
            goal,
            feedback_callback=self.feedback_callback,
        )

        self.send_goal_future.add_done_callback(
            self.goal_response_callback
        )

    def goal_response_callback(self, future):
        goal_handle = future.result()

        if not goal_handle.accepted:
            self.get_logger().info('目标被拒绝')
            return

        self.get_logger().info('目标已被接受')

        self.result_future = goal_handle.get_result_async()
        self.result_future.add_done_callback(self.result_callback)

    def feedback_callback(self, feedback_message):
        remaining = feedback_message.feedback.remaining
        self.get_logger().info(f'剩余角度：{remaining:.2f}')

    def result_callback(self, future):
        result = future.result().result
        self.get_logger().info(f'动作完成，实际角位移：{result.delta:.2f}')
        rclpy.shutdown()


def main(args=None):
    rclpy.init(args=args)

    node = RotateTurtleClient()
    node.send_goal(1.57)

    rclpy.spin(node)


if __name__ == '__main__':
    main()