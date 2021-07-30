 # Set the minimum version of CMake that can be used
 cmake_minimum_required(VERSION 3.0)

 # project name  
 project(SWAP_LIBRARY)

 # add compile options
 add_compile_options("-Wall")
 
 if (CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ansi -pedantic -Wall")
 endif() 

 # set CMAKE_BUILD_TYPE
 set( CMAKE_BUILD_TYPE Debug ) 
 
 # set output binary path  
 set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

 ############################################################
 # Create a library
 ############################################################
 
 # Generate the static library from the library sources
 add_library( utils_lib STATIC src/utils.c )

 target_include_directories( utils_lib PUBLIC ${PROJECT_SOURCE_DIR}/include )

 ############################################################
 # Create an executable
 ############################################################

 # Add an executable with the above sources
 add_executable( MAlgorithms main.c )

 # link the new swap_01 target with the swap_lib target
 target_link_libraries( MAlgorithms utils_lib )