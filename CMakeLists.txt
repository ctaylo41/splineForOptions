cmake_minimum_required(VERSION 3.0.0)
project(OptionsSpline VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 14) # Set the C++ standard to C++14
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Make C++14 a requirement

find_package(CURL REQUIRED)
find_package(nlohmann_json REQUIRED)
find_package(gtest REQUIRED)
find_package(Python3 3.11.5 COMPONENTS Interpreter Development NumPy REQUIRED)
include_directories(${Python3_INCLUDE_DIRS} ${Python3_NumPy_INCLUDE_DIRS} src/include ${GTEST_INCLUDE_DIRS} ${GMOCK_INCLUDE_DIRS} ${CURL_INCLUDE_DIRS} ${nlohmann_json_INCLUDE_DIRS})
add_executable(OptionsSpline src/main.cpp src/Graph.cpp src/matrix.cpp)
message(STATUS "GTEST ${GTEST_INCLUDE_DIRS} ${GMOCK_INCLUDE_DIRS}")
target_link_libraries(OptionsSpline PRIVATE ${CURL_LIBRARIES} nlohmann_json::nlohmann_json Python3::Python Python3::NumPy)
target_include_directories(OptionsSpline PRIVATE ${CURL_INCLUDE_DIRS})
add_executable(matrix_tests src/tests/matrix_tests.cpp src/matrix.cpp)
enable_testing()
