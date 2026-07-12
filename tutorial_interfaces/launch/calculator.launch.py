from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():

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
        parameters=[
            {"a": 10},
            {"b": 20},
            {"c": 30},
            {"operation": "mul"}
        ]
    )

    return LaunchDescription([
        server,
        client
    ])
