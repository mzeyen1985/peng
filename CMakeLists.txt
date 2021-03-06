# library CMakeLists.txt template

# minimum cmake version requirement
cmake_minimum_required(VERSION 3.6)

# project name
project(peng LANGUAGES CXX)

# capital project name string
string(TOUPPER ${PROJECT_NAME} NAME_ID)

# option for STATIC or SHARED
option(${NAME_ID}_BUILD_STATIC
    "Build a static version of this library."
    OFF
)

# option for installing the target
option(${NAME_ID}_INSTALL
    "Install the include headers and the static target (if build) of ${PROJECT_NAME}."
    ON
)

# option for building tests
option(${NAME_ID}_TESTS
    "Build unit tests for ${PROJECT_NAME}."
    OFF
)

# option for building doxygen documentation
option(${NAME_ID}_DOXYGEN
    "Build doxygen documentation for ${PROJECT_NAME}."
    OFF
)

# option for building doxygen documentation only in release mode
option(${NAME_ID}_DOXYGEN_RELEASE_ONLY
    "Build doxygen documentation for ${PROJECT_NAME} only in release mode."
    ON
)

# add source files
set(PROJECT_SOURCE_FILES
    src/version.cpp
)

# add header files
set(PROJECT_HEADER_FILES
)

# add interface header files
set(PROJECT_INTERFACE_HEADER_FILES
    include/peng/version.hpp
)

# 3rdparty dependencies
if(WIN32)
    add_subdirectory(3rdparty/dirent-1.23.2)
endif()

# add test target
if(${NAME_ID}_TESTS)
    add_subdirectory(tests)
endif()

# add doxygen target
if(${NAME_ID}_DOXYGEN)
    if(${NAME_ID}_DOXYGEN_RELEASE_ONLY)
        if(CMAKE_BUILD_TYPE MATCHES "^[Rr]elease")
            add_subdirectory(docs)
        endif()
    else()
        add_subdirectory(docs)
    endif()
endif()

# include packages
include(GenerateExportHeader)

# add library targets
if(${NAME_ID}_BUILD_STATIC)
    add_library(${PROJECT_NAME} STATIC
        ${PROJECT_SOURCE_FILES}
        ${PROJECT_HEADER_FILES}
        ${PROJECT_INTERFACE_HEADER_FILES}
    )
else()
    add_library(${PROJECT_NAME} SHARED
        ${PROJECT_SOURCE_FILES}
        ${PROJECT_HEADER_FILES}
        ${PROJECT_INTERFACE_HEADER_FILES}
    )
endif()

# set c++ standard
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

# generate export header
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)
generate_export_header(${PROJECT_NAME}
    EXPORT_FILE_NAME ${PROJECT_NAME}/peng_export.hpp
)

# add include directories
target_include_directories(${PROJECT_NAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
    PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
)

# add library dependencies
if(WIN32)
    target_link_libraries(${PROJECT_NAME}
        PRIVATE dirent
    )
endif()

# install instructions
if(${NAME_ID}_BUILD_STATIC AND ${NAME_ID}_INSTALL)
    install(targets ${PROJECT_NAME}
        DESTINATION lib
    )
elseif(NOT ${NAME_ID}_BUILD_STATIC)
    if(WIN32)
        install(TARGETS ${PROJECT_NAME}
            DESTINATION bin
        )
    else()
        install(TARGETS ${PROJECT_NAME}
            DESTINATION lib
        )
    endif()
endif()

if(${NAME_ID}_INSTALL)
    install(FILES
        ${PROJECT_INTERFACE_HEADER_FILES}
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}/peng_export.hpp
        DESTINATION include/${PROJECT_NAME}
    )
endif()