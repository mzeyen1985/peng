# minimum cmake version requirement
cmake_minimum_required(VERSION 3.6)

# detect operating system
if(WIN32)
    set(PENG_WINDOWS ON)
elseif(APPLE)
    set(PENG_APPLE ON)
elseif(UNIX)
    set(PENG_LINUX ON)
else()
    message(FATAL_ERROR "Unsupported operating system!")
endif()

# detect compiler
# message(FATAL_ERROR "${CMAKE_CXX_COMPILER_ID} MATCHES MSVC")
if("${CMAKE_CXX_COMPILER_ID}" MATCHES "MSVC")
    set(PENG_MSVC ON)
elseif("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU")
    set(PENG_GCC ON)
elseif("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
    set(PENG_CLANG ON)
else()
    message(FATAL_ERROR "Unsupported compiler!")
endif()

# create config file
configure_file(config.hpp.in ../${PROJECT_NAME}/config.hpp)

# install instructions
install(FILES
    ../${PROJECT_NAME}/config.hpp
    DESTINATION include/${PROJECT_NAME}
)