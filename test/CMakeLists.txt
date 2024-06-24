cmake_minimum_required(VERSION 3.0)

set(This Test)

set(MatrixSources
    ../src/matrix.cpp
)


set(TestSources
    matrix_tests.cpp
)


add_library(Matrix STATIC ${MatrixSources})

add_executable(${This} ${TestSources})
target_link_libraries(${This} PUBLIC
    gtest_main
    Matrix
)
add_test(
    NAME ${This}
    COMMAND ${This}
)