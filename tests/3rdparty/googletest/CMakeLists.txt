# external project CMakeLists.txt template

# minimum cmake version requirement
cmake_minimum_required(VERSION 3.6)

# project name
project(googletest)

# find package
find_package(Threads REQUIRED)

# enable external project cmake module
include(ExternalProject)

# download external project
set(EXTERNAL_PROJECT_NAME ${PROJECT_NAME}-external)
ExternalProject_Add(
    ${EXTERNAL_PROJECT_NAME}
    URL https://github.com/google/googletest/archive/master.zip
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/${EXTERNAL_PROJECT_NAME}
    # disable install step
    INSTALL_COMMAND ""
)

# get external project source and binary directories
ExternalProject_Get_Property(${EXTERNAL_PROJECT_NAME}
    SOURCE_DIR
    BINARY_DIR
)

# import subprojects of googletest
add_subdirectory(gtest)
add_subdirectory(gmock)

# create interface library
add_library(${PROJECT_NAME} INTERFACE)

# add library dependencies
target_link_libraries(${PROJECT_NAME}
    INTERFACE gtest
    INTERFACE gmock
)