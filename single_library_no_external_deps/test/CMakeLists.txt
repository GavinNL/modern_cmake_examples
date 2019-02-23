################################################################################
# This CMakeLists.txt contains the build descriptions for unit tests
################################################################################

cmake_minimum_required(VERSION 3.8.0 FATAL_ERROR)


#-------------------------------------------------------------------------------
# Test for the add( ) function
# These are just redundant examples, in we should probably loop over all the
# files and compile them
#-------------------------------------------------------------------------------
set(UNIT_TEST_SOURCE_FILE unit-add.cpp)
set(UNIT_TEST_EXE_NAME    test-add)
set(UNIT_TEST_NAME        Test-add)
set(UNIT_TEST_LINK_LIBS   math::math )
#-------------------------------------------------------------------------------

add_executable( ${UNIT_TEST_EXE_NAME}   ${UNIT_TEST_SOURCE_FILE})

# Tell the executable that we build that we need to link with the
# math::math target
target_link_libraries( ${UNIT_TEST_EXE_NAME}  ${UNIT_TEST_LINK_LIBS})

add_test( ${UNIT_TEST_NAME}  ${UNIT_TEST_EXE_NAME})
#-------------------------------------------------------------------------------



#-------------------------------------------------------------------------------
# Test for the subtract( ) function
# These are just redundant examples, in we should probably loop over all the
# files and compile them
#-------------------------------------------------------------------------------
set(UNIT_TEST_SOURCE_FILE unit-subtract.cpp)
set(UNIT_TEST_EXE_NAME    test-subtract)
set(UNIT_TEST_NAME        Test-subtract)
set(UNIT_TEST_LINK_LIBS   math::math )

add_executable( ${UNIT_TEST_EXE_NAME}   ${UNIT_TEST_SOURCE_FILE})

# Tell the executable that we build that we need to link with the
# math::math target
target_link_libraries( ${UNIT_TEST_EXE_NAME}  ${UNIT_TEST_LINK_LIBS})

add_test( ${UNIT_TEST_NAME}  ${UNIT_TEST_EXE_NAME})
#-------------------------------------------------------------------------------



#-------------------------------------------------------------------------------
# Test for the mult( ) function
# These are just redundant examples, in we should probably loop over all the
# files and compile them
#-------------------------------------------------------------------------------
set(UNIT_TEST_SOURCE_FILE unit-mult.cpp)
set(UNIT_TEST_EXE_NAME    test-mult)
set(UNIT_TEST_NAME        Test-mult)

add_executable( ${UNIT_TEST_EXE_NAME}   ${UNIT_TEST_SOURCE_FILE})

# Tell the executable that we build that we need to link with the
# math::math target
target_link_libraries( ${UNIT_TEST_EXE_NAME}  ${UNIT_TEST_LINK_LIBS})

add_test( ${UNIT_TEST_NAME}  ${UNIT_TEST_EXE_NAME})
#-------------------------------------------------------------------------------
