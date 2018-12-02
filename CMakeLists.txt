cmake_minimum_required(VERSION 3.12)
project(seqlock)
add_definitions("-std=c++17")

add_executable(seqlock src/main.cpp src/seqlock.cpp src/seqlock.h src/spinlock.cpp src/spinlock.h)


