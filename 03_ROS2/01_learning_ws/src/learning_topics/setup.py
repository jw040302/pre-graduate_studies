from setuptools import find_packages, setup

package_name = 'learning_topics'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', [
            'launch/topic_communication.launch.py',
        ]),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='wblbdd',
    maintainer_email='jw20040302@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            'topic_publisher = learning_topics.topic_publisher:main',
            'topic_subscriber = learning_topics.topic_subscriber:main',
        ],
    },
)
