# 编写基于Python的第一个节点
import rclpy
from rclpy.node import Node

def main():
    rclpy.init() # 初始化工作，分配资源
    node = Node('python_node')
    node.get_logger().info('第一个节点已创建!')
    node.get_logger().warn('第一个节点已创建?')
    rclpy.spin(node)
    rclpy.shutdown()

if __name__=='__main__':
    main()