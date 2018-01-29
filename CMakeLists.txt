cmake_minimum_required(VERSION 2.6)
project(cppstuff)

# Executable: vectordemo
add_executable(vectordemo vectordemo.cpp)

# Executable: regexdemo
add_executable(regexdemo regexdemo.c)
if(WIN32)
    find_library(regex-lib gnurx)
    if(NOT regex-lib)
        message(FATAL_ERROR "Cannot find libgnurx")
    else()
        target_link_libraries(regexdemo ${regex-lib})
    endif()
endif()
