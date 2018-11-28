cmake_minimum_required(VERSION 3.12)
project(testProject)
add_definitions("-std=c++17")

add_executable(testProject src/main.cpp src/seqlock.cpp src/seqlock.h src/spinlock.cpp src/spinlock.h)