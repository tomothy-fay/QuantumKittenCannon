cmake_minimum_required (VERSION 3.7)
project( tutorial )

# ------- #
# Release -------------------------------------------------------------------------------#
# ------- #

# Set default build type to be Release
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
endif()

message ("-- Build: " ${CMAKE_BUILD_TYPE})

# -------- #
# Compiler ------------------------------------------------------------------------------#
# -------- #

message("-- C++ compiler: " ${CMAKE_CXX_COMPILER_ID})

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")

    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 4.9)
        message(FATAL_ERROR "GCC version must be at least 4.9.")
    endif()
    
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang")

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++ -Wall")
    
else()
    message(FATAL_ERROR "Unsupported compiler.")
    
endif()

# ------------ #
# Setup Tutorial
# ------------ #

add_library( libtutorial SHARED	
        t1/rectangle.h t1/rectangle.cpp
	t2/square.h t2/square.cpp
        )

# Set directory for executables (bin/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable( t1.x t1/main.cpp )
target_link_libraries( t1.x libtutorial )

add_executable( t2.x t2/main.cpp )
target_link_libraries( t2.x libtutorial )
