#!/bin/bash

# Run script from this files pwd.
cd $(dirname $0)

# Launch vs code for development purposes. Comment out for release builds
code .

# Launch the docker application
## Prevent permission error: https://www.digitalocean.com/community/questions/how-to-fix-docker-got-permission-denied-while-trying-to-connect-to-the-docker-daemon-socket
sudo chmod 666 /var/run/docker.sock
docker run -it --rm -v $(pwd):/root/ modern-embedded-cpp-devops