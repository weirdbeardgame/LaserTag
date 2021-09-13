Project(LaserTag)
cmake_minimum_required(VERSION 3.20.2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(JSON_BuildTests OFF CACHE INTERNAL "")
set(CMAKE_BUILD_TYPE Debug)

find_package(PkgConfig REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/header)
link_directories(${CMAKE_SOURCE_DIR}/src)

set (SOURCES src/game.cpp src/server.cpp src/main.cpp src/player.cpp)
add_executable(LaserTag ${SOURCES})

