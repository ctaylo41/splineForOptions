cmake_minimum_required(VERSION 3.0.0)
project(OptionsSpline VERSION 0.1.0 LANGUAGES C CXX)

find_package(CURL REQUIRED)
find_package(nlohmann_json REQUIRED)
find_package(Python3 3.11.5 COMPONENTS Interpreter Development NumPy REQUIRED)
include_directories(${Python3_INCLUDE_DIRS} ${Python3_NumPy_INCLUDE_DIRS} src/include src)


add_executable(OptionsSpline src/main.cpp src/Graph.cpp)

target_link_libraries(OptionsSpline PRIVATE ${CURL_LIBRARIES} nlohmann_json::nlohmann_json Python3::Python Python3::NumPy)
target_include_directories(OptionsSpline PRIVATE ${CURL_INCLUDE_DIRS})

