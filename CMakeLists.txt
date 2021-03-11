cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
endif()

set(ADAPTER_FILES adapter/adapter.cpp)
add_executable(Adapter ${ADAPTER_FILES})


set(BUILDER_FILES builder/builder.cpp)
set_source_files_properties(${BUILDER_FILES} PROPERTIES COMPILE_FLAGS "-std=c++1y")
add_executable(Builder ${BUILDER_FILES})

add_subdirectory(facet-builders)