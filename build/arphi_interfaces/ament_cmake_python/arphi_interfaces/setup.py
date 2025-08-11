from setuptools import find_packages
from setuptools import setup

setup(
    name='arphi_interfaces',
    version='1.0.0',
    packages=find_packages(
        include=('arphi_interfaces', 'arphi_interfaces.*')),
)
