cmake_minimum_required(VERSION 3.10)
project(Mocha)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(CXX_COMPILER_FLAGS " -g -Wall -Wextra -pedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX_COMPILER_FLAGS}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../")

include_directories("src/include/*.h")
file(GLOB SOURCES "src/*.cpp")

add_executable(mocha ${SOURCES})