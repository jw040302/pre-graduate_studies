from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package='learning_topics',
            executable='topic_publisher',
            name='topic_publisher',
            output='screen',
        ),
        Node(
            package='learning_topics',
            executable='topic_subscriber',
            name='topic_subscriber',
            output='screen',
        ),
    ])