from launch import LaunchDescription
from launch_ros.actions import Node

from ament_index_python.packages import get_package_share_directory
import os


def generate_launch_description():

    config_file = get_package_share_directory('tutorial_interfaces') 
    config_path = os.path.join(
        config_file,
        'config',
        'calculator_params.yaml'
    )

    server = Node(
        package='tutorial_interfaces',
        executable='server',
        name='calculator_server',
        output='screen'
    )

    client = Node(
        package='tutorial_interfaces',
        executable='client',
        name='calculator_client',
        output='screen',
        parameters=[config_path]
    )

    return LaunchDescription([
        server,
        client
    ])
