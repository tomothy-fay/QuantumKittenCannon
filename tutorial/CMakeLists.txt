cmake_minimum_required (VERSION 3.7)
project( tutorial )

# -------- #
# Compiler ------------------------------------------------------------------------------#
# -------- #

# Check for supported compilers

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

# Create library (i.e. compile all the .cpp files not containing a main function)

add_library( libtutorial SHARED	
        t1/rectangle.h t1/rectangle.cpp
	t2/square.h t2/square.cpp
	t3/geometricfigure.h
	t3/rectangle2.h t3/rectangle2.cpp
	t3/square2.h t3/square2.cpp
	t4/Vector3D.h t4/Vector3D.cpp
        )

# Set directory for executables (bin/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Compile tutorial 1 and create executable
add_executable( t1.x t1/main.cpp )
target_link_libraries( t1.x libtutorial )

# Compile tutorial 2 and create executable
add_executable( t2.x t2/main.cpp )
target_link_libraries( t2.x libtutorial )

# Compile tutorial 3 and create executable
add_executable( t3.x t3/main.cpp )
target_link_libraries( t3.x libtutorial )

# Compile tutorial 4 and create executable
add_executable( t4.x t4/main.cpp )
target_link_libraries( t4.x libtutorial )
