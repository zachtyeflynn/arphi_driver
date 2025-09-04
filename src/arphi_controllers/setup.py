from setuptools import find_packages, setup

package_name = 'arphi_controllers'

setup(
    name=package_name,
    version='1.0.0',
    packages=find_packages(exclude=['test']),
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='zach',
    maintainer_email='zach@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "arphi_controller = arphi_controllers.arphi_controller:main",
            "enclosure_interface = arphi_controllers.enclosure_interface:main",
            "AR4_interface = arphi_controllers.AR4_interface:main"
        ],
    },
)