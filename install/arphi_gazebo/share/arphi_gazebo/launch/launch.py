import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, RegisterEventHandler
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import Command, FindExecutable, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from launch.event_handlers import OnProcessExit


def generate_launch_description():
    robot_description_content = Command([
        PathJoinSubstitution([FindExecutable(name="xacro")]),
        " ",
        PathJoinSubstitution([
            FindPackageShare("arphi_description"),
            "urdf",
            "arphi_gazebo.urdf.xacro",
        ]),
    ])
    robot_description = {"robot_description": robot_description_content}

    robot_state_publisher_node = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        output="both",
        parameters=[robot_description, {'use_sim_time': True}],
    )

    world = os.path.join(get_package_share_directory('arphi_gazebo'),
                         'worlds', 'empty.world')

    gazebo_bridge = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        arguments=["/clock@rosgraph_msgs/msg/Clock[ignition.msgs.Clock"],
        output='screen')

    gazebo = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            [FindPackageShare("ros_gz_sim"), "/launch", "/gz_sim.launch.py"]),
        launch_arguments={
            'gz_args':
            f'-r -v 4 --physics-engine gz-physics-bullet-featherstone-plugin {world}',
            'on_exit_shutdown': 'True'
        }.items())

    # Spawn robot
    gazebo_spawn_robot = Node(
        package="ros_gz_sim",
        executable="create",
        arguments=["-name", "", "-topic", "robot_description"],
        output="screen",
        parameters=[{'use_sim_time': True}],
    )

    # Spawner for both the joint_state_broadcaster and the joint_trajectory_controller
    # The controllers are listed sequentially in the arguments list.
    controller_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=[
            "joint_state_broadcaster",
            "joint_trajectory_controller",
            "--controller-manager", "/controller_manager"
        ],
    )

    return LaunchDescription([
        robot_state_publisher_node,
        gazebo_bridge,
        gazebo,
        gazebo_spawn_robot,
        # Start the controller spawner after the robot has been spawned
        RegisterEventHandler(
            event_handler=OnProcessExit(
                target_action=gazebo_spawn_robot,
                on_exit=[controller_spawner],
            )
        ),
    ])