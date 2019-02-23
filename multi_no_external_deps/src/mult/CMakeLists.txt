################################################################################
# This CMakeLists.txt file builds a Single C++ Library which:
#
# - Does not depend on any external libraries (eg: boost), therefore does not
#   need to call find_package( )
# - Provides unit tests
# - Provides an installation
# - Provides packaging via CPACK
#
################################################################################

cmake_minimum_required(VERSION 3.8.0 FATAL_ERROR)


################################################################################
# Edit these
################################################################################

# The project information. The name you give the project, eg: math, will be
# the name of the compiled library in the end: eg libadd.a
project( mult
         LANGUAGES CXX
         VERSION 1.0.0.0
         DESCRIPTION "A simple library to do math operations."
)


set(PROJECT_NAMESPACE_NAME math)  # The namespace we will put the target
                                  # since this is a single library called "math"
                                  # we shall namespace this as math::math

# Add your source files here. Do not use FILE(GLOB) as it is not
# considered best practice by CMAKE
add_library(  ${PROJECT_NAME}
              mult.cpp
           )

# Alias our library as a target. we are going to call it
#  math::add
add_library(${PROJECT_NAMESPACE_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})


# Set that we want to use C++17 to build this project
# DO NOT manually add the -std=c++17 flag
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

target_include_directories( ${PROJECT_NAME}
                           PUBLIC
                                $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
                                $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                                $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
                                $<INSTALL_INTERFACE:/include>
                                )

# Which libraries do each of these projects need to link with.
target_link_libraries( ${PROJECT_NAME}  PUBLIC  math::add)


# Set the install targets.
install( TARGETS  ${PROJECT_NAME} EXPORT ${PROJECT_NAME}Targets
         LIBRARY  DESTINATION lib
         ARCHIVE  DESTINATION lib
         RUNTIME  DESTINATION bin
         )

install( EXPORT ${PROJECT_NAME}Targets
         FILE   ${PROJECT_NAME}Targets.cmake
         NAMESPACE ${PROJECT_NAME}::
         DESTINATION lib/cmake/${PROJECT_NAME} )

install(DIRECTORY
           "${CMAKE_CURRENT_LIST_DIR}/include"
           "${CMAKE_CURRENT_BINARY_DIR}/include"
           "${CMAKE_SOURCE_DIR}/include/"
           DESTINATION .
         FILES_MATCHING PATTERN "*${PROJECT_NAME}/*.h")

################################################################################
