import rclpy
from rclpy.node import Node
from learning_interfaces.srv import CalculateRectangleArea


class RectangleAreaClient(Node):
    def __init__(self):
        super().__init__('rectangle_area_client')

        self.client = self.create_client(
            CalculateRectangleArea,
            '/calculate_rectangle_area',
        )

        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('正在等待矩形面积服务……')

    def send_request(self, length, width):
        request = CalculateRectangleArea.Request()
        request.length = length
        request.width = width

        return self.client.call_async(request)


def main(args=None):
    rclpy.init(args=args)
    node = RectangleAreaClient()

    length = 5.0
    width = 2.5

    future = node.send_request(length, width)
    rclpy.spin_until_future_complete(node, future)

    response = future.result()
    node.get_logger().info(
        f'计算结果：{length} × {width} = {response.area}'
    )

    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()