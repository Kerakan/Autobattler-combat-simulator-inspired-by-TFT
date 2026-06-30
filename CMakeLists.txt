cmake_minimum_required(VERSION 3.15)
project(Autobattler VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Collect all .cpp sources in the project root
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/*.cpp)
list(FILTER SOURCES EXCLUDE REGEX "build/")

add_executable(autobattler ${SOURCES})

target_include_directories(autobattler PRIVATE ${CMAKE_SOURCE_DIR})

if(MSVC)
  target_compile_options(autobattler PRIVATE /W4 /permissive-)
else()
  target_compile_options(autobattler PRIVATE -Wall -Wextra -Wpedantic)
endif()

message(STATUS "Sources: ${SOURCES}")