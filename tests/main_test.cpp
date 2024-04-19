#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../lib/doctest.h"

// Function to add two numbers
int add(int a, int b) {
    return a + b;
}

// Test case for the add function
TEST_CASE("Testing addition function") {
    // Test case 1
    CHECK(add(1, 2) == 3);

    // Test case 2
    CHECK(add(-1, 2) == 1);

    // Test case 3
    CHECK(add(0, 0) == 0);
}

