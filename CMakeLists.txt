cmake_minimum_required(VERSION 3.10)
project(Lexer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

# Include directories
include_directories(src) #Old
include_directories(src/include)
# Add source files
file(GLOB components_sources src/Components/*.cpp)
add_library(Lexer src/Lexer.cpp
    src/InputStream.cpp
    ${components_sources}
    
)

add_executable(LexerMain src/main.cpp)
target_link_libraries(LexerMain Lexer)

# Add Google Test
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add test executable
add_executable(LexerTest tests/LexerTest.cpp)
target_link_libraries(LexerTest Lexer ${GTEST_LIBRARIES} pthread)
