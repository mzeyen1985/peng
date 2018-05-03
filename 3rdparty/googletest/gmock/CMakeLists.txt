# external project CMakeLists.txt template

# minimum cmake version requirement
cmake_minimum_required(VERSION 3.6)

# project name
project(gmock)

# create source directory with include path.
# this is necessary to configure interface include directories.
execute_process(
    COMMAND ${CMAKE_COMMAND} -E make_directory ${SOURCE_DIR}/googlemock/include
)

# create imported target to be used as a dependency by programs
add_library(${PROJECT_NAME} STATIC IMPORTED GLOBAL)

# set project properties
set_target_properties(${PROJECT_NAME} PROPERTIES
    IMPORTED_LOCATION ${BINARY_DIR}/googlemock/libgmock.a
    IMPORTED_LINK_INTERFACE_LIBRARIES ${CMAKE_THREAD_LIBS_INIT}
)

# add external project as dependency
target_link_libraries(${PROJECT_NAME}
    INTERFACE ${EXTERNAL_PROJECT_NAME}
)

# add external project include directories
target_include_directories(${PROJECT_NAME}
    INTERFACE ${SOURCE_DIR}/googlemock/include
)