cmake_minimum_required(VERSION 3.0)

project(contactmanager)

add_executable(contactmanager main.cpp)

install(TARGETS contactmanager RUNTIME DESTINATION bin)
