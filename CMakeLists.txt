cmake_minimum_required(VERSION 3.16)
project(pendulum)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

include_directories(include)
include_directories(vendored/glm)

add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)

file(GLOB MY_SOURCES "src/*.cpp" "include/*.hpp" )
add_executable(${PROJECT_NAME} ${MY_SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)