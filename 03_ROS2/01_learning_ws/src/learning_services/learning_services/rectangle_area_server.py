import rclpy
from rclpy.node import Node
from learning_interfaces.srv import CalculateRectangleArea


class RectangleAreaServer(Node):
    def __init__(self):
        super().__init__('rectangle_area_server')

        self.service = self.create_service(
            CalculateRectangleArea,
            '/calculate_rectangle_area',
            self.calculate_callback,
        )

        self.get_logger().info('矩形面积服务已启动')

    def calculate_callback(self, request, response):
        response.area = request.length * request.width

        self.get_logger().info(
            f'收到请求：{request.length} × {request.width}'
            f' = {response.area}'
        )

        return response


def main(args=None):
    rclpy.init(args=args)
    node = RectangleAreaServer()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()