FROM ubuntu:20.04
ENV DEBIAN_FRONTEND noninteractive

# Req for sudo apt installs
RUN apt-get update

# Install snap for certain dependencies. Like CMake
# https://forum.snapcraft.io/t/install-snap-in-docker/20740/3
RUN apt-get install -y snapd squashfuse fuse
# RUN systemctl enable snapd
RUN systemctl unmask snapd.service
RUN systemctl enable snapd.service
RUN systemctl start snapd.service

# GCC/G++ and dependices for many other .deb
RUN apt-get install -y build-essential

# Cmake - Build system
# RUN apt-get install -y cmake
RUN snap install cmake --classic

# GDB - Debug
RUN apt-get install -y gdb

# Python - Scripting 
RUN apt-get install -y python3 python3-pip

# Git 
RUN apt-get install -y git

# Clang Tidy - Analyzer
RUN apt-get install -y clang-tidy

# Clang Format - Auto-format
RUN apt-get install -y clang-format

# Doxygen - Documentation
RUN apt-get install -y doxygen

# LCOV      // GCOV included w/ google test
RUN apt-get install -y lcov

# Protobuf dependencies. Protobuff installed via CMake
# Install mini protobuf 
# RUN apt-get install -y autoconf automake libtool curl make g++ unzip

# Codespell - Spell checker
RUN pip3 install codespell

# Cmake init - CMake project template. Is greatly modified + extended
# https://github.com/friendlyanon/cmake-init
RUN pip3 install cmake-init

#########       MISC TOOLS      ########
RUN apt-get install -y tree vim wget curl

# Where to start docker container
WORKDIR /root