#!/bin/bash
# https://gist.github.com/stephenturner/e3bc5cfacc2dc67eca8b
cat /etc/centos-release
sudo yum update binutils
sudo yum install epel-release
sudo yum install mesa-libGL-devel xcb-util-image-devel libudev-devel libjpeg-devel openal-devel libvorbis-devel flac-devel
wget http://www.sfml-dev.org/files/SFML-2.3.2-linux-gcc-64-bit.tar.gz -O /tmp/sfml.tar.gz
tar -xzvf /tmp/sfml.tar.gz
sudo cp -r SFML-2.3.2/* /usr/
sudo rpm --import http://ftp.scientificlinux.org/linux/scientific/5x/x86_64/RPM-GPG-KEYs/RPM-GPG-KEY-cern
sudo wget -O /etc/yum.repos.d/slc6-devtoolset.repo http://linuxsoft.cern.ch/cern/devtoolset/slc6-devtoolset.repo
sudo yum install devtoolset-2-gcc-c++ 
#sudo yum install devtoolset-2
echo "Enable devtoolset-2"
source /opt/rh/devtoolset-2/enable
#sudo scl enable devtoolset-2 bash
gcc --version
g++ --version
