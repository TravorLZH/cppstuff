cmake_minimum_required(VERSION 2.6)
project(cppstuff)

include_directories("${PROJECT_SOURCE_DIR}/include")

# Executable: vectordemo
add_executable(vectordemo vectordemo.cpp)

# Executable: regexdemo
add_executable(regexdemo regexdemo.c)

# Library: libvoid
add_library(void swap.c lsearch.c)

# Executable: swapdemo
add_executable(swapdemo swapdemo.c)
target_link_libraries(swapdemo void)

# Executable: searchdemo
add_executable(searchdemo searchdemo.c)
target_link_libraries(searchdemo void)

# Executable: customcmpsearch
add_executable(customcmpsearch customcmpsearch.c)
target_link_libraries(customcmpsearch void)

# Executable: posixeredemo
add_executable(posixeredemo posixeredemo.c)

# Executable: globalctordemo
add_executable(globalctors globalctors.c)

if(WIN32)
	find_library(regex-lib gnurx)
	if(NOT regex-lib)
		message(FATAL_ERROR "Cannot find libgnurx")
	else()
        	target_link_libraries(regexdemo ${regex-lib})
		target_link_libraries(posixeredemo ${regex-lib})
	endif()
endif()
