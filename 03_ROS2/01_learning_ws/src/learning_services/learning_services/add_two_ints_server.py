import rclpy
from rclpy.node import Node
from example_interfaces.srv import AddTwoInts


class AddTwoIntsServer(Node):
    def __init__(self):
        super().__init__('add_two_ints_server')

        self.service = self.create_service(
            AddTwoInts,
            '/add_two_ints',
            self.add_callback,
        )

        self.get_logger().info('加法服务已启动')

    def add_callback(self, request, response):
        response.sum = request.a + request.b

        self.get_logger().info(
            f'收到请求：{request.a} + {request.b} = {response.sum}'
        )

        return response


def main(args=None):
    rclpy.init(args=args)
    node = AddTwoIntsServer()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()