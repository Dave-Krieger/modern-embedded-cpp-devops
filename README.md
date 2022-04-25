# What is this project?
An example repo showcasing a modern embedded build system. 
- It uses docker for host 'containerization'
- CMake to build host and target executables
- A range of dev ops tools
  - Automated Testing & Reporting
  - Static & runtime analyzers
  - Formatter
  - Documentation
  - Pipelines

See my associated yocto repo for information about building the target's img. 

# Table of contents
- TODO

# Automated Testing and Reporting
1. Google Test
2. GCov to generate report metadata for LCov
3. LCov to generate pretty report 

# Code analyzers
## Static
1. Cpp-check
## Run-time
1. Clang-tidy
2. Sanitizers
    * Addresses and Leaks   (ASAN)
    * Undefined Behaviour   (USAN)
    * Thread                (TSAN)

# Formatting
1. Clang-format
2. Clang-tidy

# Documentation
1. Doxygen

# Requirements
1. Docker
2. Internet Connection
   1. Used for download packages w/ docker container and CMake fetch content

# How to use (assumes linux)
1. clone the project
    git clone dave.git
2. Then follow instructions to launch docker for either Linux or Windows
3. After docker is launched, build the binary as desired see how does it work.
## Linux
1. Click the script :)
   
## Windows
1. @todo, but it should be something like this
2. open cmd:
    win key + r: cmd
3. build docker
    docker build -t myubuntu  .
4. Run docker with continer mounted at pwd
    docker run -it --rm -v %cd%:/root/ myubuntu bash

# How does it work and how do I build?
1. Build the docker container
   1. This will install all of the Ubuntu dependencies required to run all of the tools
   2. This will install some of the C++ tools, but not all.
2. Run the docker container
3. Build binary according to the developer's needs

As a developer, you may want to do a range of things. 
1. Build standard binary for either host/target
2. Run automated testing for either host/target
3. Run static analysis on binary (host only)

## Standard binary
To build for host
    cmake .. -DTarget=0

To build for target
    cmake .. -DTarget=1

What tools are used during the 'standard' binary
- Long list of GCC/G++ flags. Like -Wall but more
- ASAN - Default sanitizer

## Automated Testing
To build tests for host
    cmake .. -DTarget=0 -Dtest=1

To build tests for target
    cmake .. -DTarget=0 -Dtest=1

To build tests for target using hwil
    cmake .. -DTarget=0 -Dtest=1 -Dhwil=1

What tools are used during for the 'test' binary
- Standard binary tools
- Google test
- LCov & GCov

## Static analysis
To run analyzers and formatters on the code
    cmake .. -Danalyze=0

What tools are used during for the 'analysis' binary
- Cppcheck
- Clang Format
- Clang Tidy
- Codespell

## CMake flags
Users can add any of the following flags during the CMake invocation
Santizers:
- -DDasan
- -DDusan
- -Dtsan

### FAQ - Running CMake or Make takes a long time
1. The first time you run cmake/make it may take some time. CMake will use FetchContent and ExternalProject to install required C++ projects.
CMake projects which are downloaded and built
- Cppcheck
- Googletest


# Additional reading
**Read more about the different tools, workflow, or w/e, see ~~/docs/instructions-readmes/*.md**
- docker
- doxygen
- git-workflow
- proj-structure

Note: the ~~ is my shorthand for the gitroot of the project