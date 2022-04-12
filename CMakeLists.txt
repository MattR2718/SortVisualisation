cmake_minimum_required(VERSION 3.0.0)
project(SortVisualisation VERSION 0.1.0)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

find_package(GTest)
include_directories(${GTEST_INCLUDE_DIRS})

find_package(X11 REQUIRED)
find_package(Threads REQUIRED)

include_directories(/usr/include/SFML/)
link_directories(/usr/lib/aarch64-linux-gnu/)

add_executable(${PROJECT_NAME} main.cpp)
add_executable(Test test.cpp)

target_link_libraries(Test GTest::GTest GTest::Main sfml-graphics sfml-window sfml-system X11)
target_link_libraries (${PROJECT_NAME} sfml-graphics sfml-window sfml-system X11)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)