import rclpy
from rclpy.node import Node
from std_msgs.msg import String


class TopicSubscriber(Node):
    def __init__(self):
        super().__init__('topic_subscriber')

        self.subscription = self.create_subscription(
            String,
            '/learning_chatter',
            self.listener_callback,
            10,
        )

    def listener_callback(self, message):
        self.get_logger().info(f'Received: "{message.data}"')


def main(args=None):
    rclpy.init(args=args)

    node = TopicSubscriber()
    rclpy.spin(node)

    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()