cmake_minimum_required(VERSION 3.29)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

project(MonkeyInterpreter VERSION 0.1.0)

# the -I flag in gcc
# include_directories(${PROJECT_SOURCE_DIR}/include/)

set(APP_SOURCES
  src/main.cpp
  src/lexer.cpp
  src/token.cpp
  src/repl.cpp
)

# Create a library from the source files
add_library(monkey_lib ${APP_SOURCES})

# creates ./build/bin/MonkeyInterpreter
add_executable(${PROJECT_NAME} ${APP_SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE monkey_lib)

enable_testing()
add_subdirectory(tests)
