cmake_minimum_required(VERSION 3.10)
project(TwoSum C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -g")

# ── Build main program ─────────────────────────────────────────────────────────
add_executable(two_sum
    src/main.c
    src/two_sum.c
)
target_include_directories(two_sum PRIVATE src)

# ── Build and run tests ────────────────────────────────────────────────────────
add_executable(test_two_sum
    src/two_sum.c
    tests/test_two_sum.c
)
target_include_directories(test_two_sum PRIVATE src)
target_compile_definitions(test_two_sum PRIVATE TESTING)

enable_testing()
add_test(NAME TwoSumTests COMMAND test_two_sum)