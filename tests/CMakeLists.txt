# tests/CMakeLists.txt

# Add the test executable and specify all test source files
add_executable(monkey_tests
    lexer_test.cpp
)

# Set the target properties, such as C++ standard
target_compile_features(monkey_tests PRIVATE cxx_std_20)

# Link the library containing the source files to the test executable
target_link_libraries(monkey_tests PRIVATE monkey_lib)
