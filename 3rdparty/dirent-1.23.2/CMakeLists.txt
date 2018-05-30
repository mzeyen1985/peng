# header-only CMakeLists.txt template

# minimum cmake version requirement
cmake_minimum_required(VERSION 3.6)

# project name
project(dirent)

# add header-only target
add_library(${PROJECT_NAME} INTERFACE)

# add include directories
target_include_directories(${PROJECT_NAME}
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include
)