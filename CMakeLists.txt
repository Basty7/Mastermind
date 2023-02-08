cmake_minimum_required(VERSION 3.23)
project(mastermind)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")
set(APP_ICON_RESOURCE_WINDOWS "${CMAKE_CURRENT_SOURCE_DIR}/ressources.rc")

add_executable(mastermind main.cpp ressources.rc)
