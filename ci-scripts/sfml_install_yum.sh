#!/bin/bash
cat /etc/centos-release
sudo yum install epel-release
sudo yum install mesa-libGL-devel xcb-util-image-devel libudev-devel libjpeg-devel openal-devel libvorbis-devel flac-devel
wget http://www.sfml-dev.org/files/SFML-2.3.2-linux-gcc-64-bit.tar.gz -O /tmp/sfml.tar.gz
tar -xzvf /tmp/sfml.tar.gz
sudo cp -r SFML-2.3.2/* /usr/

