# 指定最低CMAKE版本
cmake_minimum_required(VERSION 3.10)
project(design CXX)

# 设置c++ 标准
#set(CMAKE_CXX_STANDARD 11)

# 设置当前编译模式
SET(CMAKE_BUILD_TYPE "Debug")

# 分别设置DEBUG模式以及RELASE模式下的参数
set(CMAKE_CXX_FLAGS_DEBUG  "${CMAKE_CXX_FLAGS} -O0 -Wall -Werror -g2 -ggdb -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O3 -Wall -Werror")


set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(design)



