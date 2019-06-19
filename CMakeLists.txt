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

# Executable: bitfield
add_executable(bitfield bitfield.c)

# Executable: structdemo
add_executable(structdemo structdemo.c)

# Executable: factor
add_executable(factor factor.c)

# Executable: squareroot
add_executable(squareroot squareroot.c)

# Executable: binarysearch
add_executable(binarysearch binarysearch.c)

# Executable: cpudemo
add_executable(cpudemo cpudemo.c)

# Executable: ipaddr
add_executable(ipaddr ipaddr.c)

# Executable: ftpdemo
add_executable(ftpdemo ftpdemo.c)

# Executable: primefactor
add_executable(primefactor primefactor.c)

if(WIN32)
	find_library(regex-lib gnurx)
	if(NOT regex-lib)
		message(FATAL_ERROR "Cannot find libgnurx")
	else()
        	target_link_libraries(regexdemo ${regex-lib})
		target_link_libraries(posixeredemo ${regex-lib})
	endif()
endif()
