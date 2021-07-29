cmake_minimum_required (VERSION 3.0.0)
project (mastering-algorithms C)

if (CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ansi -pedantic -Wall")
endif()

add_library(utils utils.c)
add_executable(test test.c)
target_link_libraries(leptjson_test leptjson)

