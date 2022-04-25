#!/bin/bash

# CD to this script PWD. Then up 2 dirs to gitroot
cd $(dirname $0)
cd ../../

# Build docker image
# Building image can mess with user perms: https://stackoverflow.com/questions/41286028/docker-build-error-checking-context-cant-stat-c-users-username-appdata
sudo chown -R $USER $(pwd)
docker build -t modern-embedded-cpp-devops .