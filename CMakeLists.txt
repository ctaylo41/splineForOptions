cmake_minimum_required(VERSION 3.0.0)
set(This OptionsSpline)
project(OptionsSpline VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 14) # Set the C++ standard to C++14
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Make C++14 a requirement
set(CMAKE_POSITION_INDEPENDENT_CODE ON) 

enable_testing()
add_subdirectory(googletest)

set(Headers
    src/Graph.h
    src/matrix.h
    src/vector.h
    src/PriceData.h
)

set(Sources
    src/main.cpp
    src/Graph.cpp
    src/matrix.cpp
    src/vector.cpp
    src/PriceData.cpp
)

add_executable(${This} ${Sources} ${Headers})

add_subdirectory(test)

find_package(CURL REQUIRED)
find_package(nlohmann_json REQUIRED)

find_package(Python3 3.11.5 COMPONENTS Interpreter Development NumPy REQUIRED)
target_link_libraries(OptionsSpline PRIVATE ${CURL_LIBRARIES} nlohmann_json::nlohmann_json Python3::Python Python3::NumPy)
target_include_directories(OptionsSpline PRIVATE ${CURL_INCLUDE_DIRS})

