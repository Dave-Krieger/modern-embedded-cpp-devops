# Project structure
## Brief description of each directory
* build/
  * directory used for builds, contains no long term code.
  * Do not push this dir to master (.gitignore will catch it for you)
  
* cmake/
  * List of .cmake files containing external project downloads
    * Configures flags and links as necessary per 'tool' 
  
* include/
  * Projects 'core' /include folder for .h and .hpp files
  
* src/
  * Projects 'core' /src folder for .c and .cpp files
  * CMakeLists.txt for 'core' bin generation

* test/
  * Contains gtest style .cpp test files
  * CMakeLists.txt for 'test' bin generation

*Fill in more here*

## Important files
* Dockerfile
  * Docker container configuration and setup
  
* CMakeLists.txt
  * Root cmake list used for building the project
    * src/ and test/ each have their own child CMakeLists.txt for the binaries they generate
  
* .gitignore
  * Ignore various dirs for git. Like build and some others

* .clang-format
  * Clang formatter configuration file.