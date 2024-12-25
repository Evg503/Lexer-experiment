cmake_minimum_required(VERSION 3.10)
project(LexerTests)

set(CMAKE_CXX_STANDARD 17)

# Add Google Test
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add test executable
add_executable(LexerTest LexerTest.cpp)
target_link_libraries(LexerTest ${GTEST_LIBRARIES} pthread)

# Add tests
add_test(NAME LexerTest COMMAND LexerTest)
