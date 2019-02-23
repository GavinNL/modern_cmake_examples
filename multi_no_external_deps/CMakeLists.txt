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
# the name of the compiled library in the end: eg libmath.a
project( math
         LANGUAGES CXX
         VERSION 1.0.0.0
         DESCRIPTION "A simple library to do math operations."
)


set(PROJECT_NAMESPACE_NAME math)  # The namespace we will put the target
                                  # since this is a single library called "math"
                                  # we shall namespace this as math::math

add_library( ${PROJECT_NAME} INTERFACE)

target_link_libraries( ${PROJECT_NAME}  INTERFACE  math::add)


add_subdirectory(src/add)
add_subdirectory(src/mult)
add_subdirectory(src/subtract)

enable_testing()
add_subdirectory(test)
