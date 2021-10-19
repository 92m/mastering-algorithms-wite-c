 # Set the minimum version of CMake that can be used
 cmake_minimum_required(VERSION 3.0)

 # project name  
 project(MAlgorithms)

 # add compile options
 add_compile_options("-Wall")
 
 if (CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ansi -pedantic -Wall")
 endif() 

 # set CMAKE_BUILD_TYPE
 set( CMAKE_BUILD_TYPE Debug ) 
 
 # set output binary path  
 set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

 set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

 ############################################################
 # Create a library
 ############################################################
 
 # Generate the static library from the library sources
 add_library( utils_mAlgorithms 
  src/utils.c 
  src/list.c 
  src/dlist.c 
  src/clist.c 
  src/page.c 
  src/stack.c 
  src/queue.c 
  src/set.c 
  src/chtbl.c
  src/ohtbl.c
  src/bitree.c
  src/bistree.c
  src/traverse.c
)

 target_include_directories( utils_mAlgorithms PUBLIC ${PROJECT_SOURCE_DIR}/include )

 ############################################################
 # Create an executable
 ############################################################

 # Add an executable with the above sources
 add_executable( MAlgorithms_test main.c)

 # link the new swap_01 target with the swap_lib target
 target_link_libraries( MAlgorithms_test utils_mAlgorithms )