cmake_minimum_required(VERSION 2.8)
project(tinyrenderer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -Werror -O0 -ggdb -pg")

set(SOURCE_FILES src/tgaimage.cpp src/main.cpp)
add_executable(tinyrenderer ${SOURCE_FILES})
