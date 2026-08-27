from setuptools import find_packages, setup

package_name = 'learning_services'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
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
            'add_two_ints_server = learning_services.add_two_ints_server:main',
            'add_two_ints_client = learning_services.add_two_ints_client:main',
            'rectangle_area_server = learning_services.rectangle_area_server:main',
        ],
    },
)
