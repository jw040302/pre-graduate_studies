"""Launch turtlesim together with the configurable patrol node."""

import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue


def generate_launch_description():
    """Create the complete turtlesim patrol launch description."""
    package_share = get_package_share_directory('turtle_patrol')
    default_config = os.path.join(package_share, 'config', 'patrol.yaml')

    config_argument = DeclareLaunchArgument(
        'config_file',
        default_value=default_config,
        description='巡逻参数文件路径',
    )
    autostart_argument = DeclareLaunchArgument(
        'autostart',
        default_value='true',
        description='启动后是否立即开始巡逻',
    )

    turtlesim_node = Node(
        package='turtlesim',
        executable='turtlesim_node',
        name='turtlesim',
        output='screen',
    )
    patrol_node = Node(
        package='turtle_patrol',
        executable='patrol_node',
        name='turtle_patrol',
        output='screen',
        parameters=[
            LaunchConfiguration('config_file'),
            {
                'autostart': ParameterValue(
                    LaunchConfiguration('autostart'),
                    value_type=bool,
                ),
            },
        ],
    )

    return LaunchDescription([
        config_argument,
        autostart_argument,
        turtlesim_node,
        patrol_node,
    ])
