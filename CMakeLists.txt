cmake_minimum_required(VERSION 2.6)
project(cppstuff)

# Executable: vectordemo
add_executable(vectordemo vectordemo.cpp)

# Executable: regexdemo
add_executable(regexdemo regexdemo.c)
target_link_libraries(regexdemo)
