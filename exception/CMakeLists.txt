cmake_minimum_required(VERSION 3.18)
project(exception)

include_directories("../libexception/src")

set(SOURCE_FILES
 src/main.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# install(DIRECTORY ../test-data DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Debug)

target_link_libraries(${PROJECT_NAME} libexception)
