import rclpy
from rclpy.node import Node


def main(args=None):
        rclpy.init(args=args)

        node = Node('hello_node')
        node.get_logger().info('我的第一个标准 ROS 2 Python 节点已启动！')

        rclpy.spin(node)

        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
        main()