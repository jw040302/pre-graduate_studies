from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue


def generate_launch_description():
    publish_period = LaunchConfiguration('publish_period')

    return LaunchDescription([
        DeclareLaunchArgument(
            'publish_period',
            default_value='0.5',
            description='发布消息的时间间隔，单位为秒',
        ),
        Node(
            package='learning_topics',
            executable='topic_publisher',
            name='topic_publisher',
            output='screen',
            parameters=[{
                'publish_period': ParameterValue(
                    publish_period,
                    value_type=float,
                ),
            }],
        ),
        Node(
            package='learning_topics',
            executable='topic_subscriber',
            name='topic_subscriber',
            output='screen',
        ),
    ])