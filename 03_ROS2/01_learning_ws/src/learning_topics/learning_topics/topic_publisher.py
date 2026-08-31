import rclpy
from rcl_interfaces.msg import SetParametersResult
from rclpy.node import Node
from std_msgs.msg import String


class TopicPublisher(Node):
    def __init__(self):
        super().__init__('topic_publisher')

        self.publisher = self.create_publisher(
            String,
            '/learning_chatter',
            10,
        )

        self.declare_parameter('publish_period', 0.5)
        publish_period = self.get_parameter('publish_period').value

        self.message_count = 0
        self.timer = self.create_timer(publish_period, self.publish_message)
        self.add_on_set_parameters_callback(self.parameter_callback)

    def parameter_callback(self, parameters):
        for parameter in parameters:
            if parameter.name == 'publish_period':
                if parameter.value <= 0.0:
                    return SetParametersResult(
                        successful=False,
                        reason='publish_period必须大于0',
                    )

                self.destroy_timer(self.timer)
                self.timer = self.create_timer(
                    parameter.value,
                    self.publish_message,
                )

                self.get_logger().info(
                    f'发布周期已修改为：{parameter.value}秒'
                )

        return SetParametersResult(successful=True)

    def publish_message(self):
        message = String()
        message.data = f'Hello ROS 2: {self.message_count}'

        self.publisher.publish(message)
        self.get_logger().info(f'Published: "{message.data}"')

        self.message_count += 1


def main(args=None):
    rclpy.init(args=args)

    node = TopicPublisher()
    rclpy.spin(node)

    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
