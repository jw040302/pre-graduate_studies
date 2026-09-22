"""Setuptools configuration for the turtle_patrol ROS 2 package."""

import os
from glob import glob

from setuptools import find_packages, setup

package_name = 'turtle_patrol'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'),
            glob('launch/*.launch.py')),
        (os.path.join('share', package_name, 'config'),
            glob('config/*.yaml')),
        (os.path.join('share', package_name), ['README.md']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='wblbdd',
    maintainer_email='jw20040302@gmail.com',
    description='Closed-loop multi-waypoint patrol demo for turtlesim.',
    license='Apache-2.0',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            'move_forward = turtle_patrol.move_forward:main',
            'patrol_node = turtle_patrol.patrol_node:main',
        ],
    },
)
