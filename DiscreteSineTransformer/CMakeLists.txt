cmake_minimum_required(VERSION 3.7)
project(DST_Test)

add_compile_options(-O3)



set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp DiscreteSineTransformer2D.cpp)

#SOME MAGIC HAPPENS HERE TO LINK TO THE FFTW LIBRARY
find_library(FFTW_LIBRARY NAMES fftw3)
add_library(fftw3 UNKNOWN IMPORTED)
set_property(TARGET fftw3 PROPERTY IMPORTED_LOCATION "${FFTW_LIBRARY}")

add_executable(DST_Test ${SOURCE_FILES})


target_link_libraries(DST_Test fftw3)


