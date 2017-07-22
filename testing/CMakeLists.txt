cmake_minimum_required(VERSION 2.6)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with our tests
add_executable( runTests.out tests.cpp )
target_link_libraries(runTests.out ${GTEST_LIBRARIES} pthread)
