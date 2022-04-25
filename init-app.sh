#!/bin/bash

# Build the project for host system using cmake-init

# cmake-init app
# Modify the app/HACKING.md 
    # Line 44:       "inherits": ["dev-mode", "ci-<os>"],
    # change os to unix

# Modify CMakePresets.json and remove all isntances of windows
    # We will be running this from a docker unix container. So its safe to do

# Modify CMakeUserPresets.json and remove all instances of windows


# add version

# addd description

# add hoempageurel

# add target type : exec, header, static/shared

# c version
# clang tidy, y
# cpp chekc, y

# cmake --preset=dev
# cmake --build --preset=dev
# cmake --build --preset=dev -t run-exe

# ctest --preset=dev]
