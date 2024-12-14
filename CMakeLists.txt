cmake_minimum_required(VERSION 3.10)

project(Calculator)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


set(SOURCES
        src/main.cpp
)

add_executable(calculator ${SOURCES})
