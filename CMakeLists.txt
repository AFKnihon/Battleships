cmake_minimum_required(VERSION 3.29)
project(codin)

set(CMAKE_CXX_STANDARD 14)

include_directories(../.vscode)

add_executable(codin
        ../.vscode/
        main.cpp)
