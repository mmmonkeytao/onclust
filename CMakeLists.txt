cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
# --------------------------------------------------------------
# Indicate CMake 2.8 and above that we don't want to mix relative
#  and absolute paths in linker lib lists.
# Run "cmake --help-policy CMP0042" for more information.
# --------------------------------------------------------------
if(COMMAND cmake_policy)
  cmake_policy(SET CMP0042 NEW)
endif(COMMAND cmake_policy)

# online star clustering learning
project(oscl) 

set(OSCL_NAMESPACE oscl)

# Make sure stuff goes in to the correct places in the build dir
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

########################
# system configuration
########################
# MAC OS
if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  add_definitions(-arch x86_64)
endif()

# Point CMake to the directory containing various build scripts
set(CMakeScripts_MODULE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
list(APPEND CMAKE_MODULE_PATH "${CMakeScripts_MODULE_DIR}")

# Bring in helper functions to make dealing
# with cache internal variables easier 
include(CacheInternalHelpers)

########################
# compiler settings
########################
# major working compiler clang++3.5
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++ -Wall -g -O3")

########################
# Package Use 
########################
# Eigen  
set(EIGEN_INCLUDE_DIR "/usr/local/Cellar/eigen/3.2.2/include/eigen3/")
include_directories(${EIGEN_INCLUDE_DIR})

# add source file
set(SOURCES src/OnClust.cpp
            src/Vertex.cpp
	    src/IO.cpp
	    src/Vmeasure.cpp
	    src/computeSimilarity.cpp	    
	    src/EBC.cpp
	    src/Hquery_accuracy.cpp
	    src/oscInsert.cpp
	    src/helper.cpp
	    src/oscUpdate.cpp
	    src/OSC.cpp
	    )

set(HEADER_SUBDIR "include")

set(PUBLIC_HEADERS include/Vertex.h
                   include/OnClust.h
		   		   )

set(OnClust_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(OnClust_LIBRARY onclust)

include_directories(${OnClust_INCLUDE})

cache_internal_init_unique(OnClust_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/include)
cache_internal_init_unique(OnClust_LIBRARY OnClust)

add_library(${OnClust_LIBRARY} ${SOURCES} ${PUBLIC_HEADERS})
#target_link_libraries(${OSCL_GALAXY_LIBRARY} ${STXXL_LIBRARIES})

#cache_internal_append_unique(OSCL_LIBRARIES ${OSCL_GALAXY_LIBRARY})