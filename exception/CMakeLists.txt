cmake_minimum_required(VERSION 3.18)
project(exceptionapp)

include_directories("../libexception/src")

set(SOURCE_FILES
 src/main.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

install(TARGETS ${PROJECT_NAME} DESTINATION .)

target_link_libraries(${PROJECT_NAME} Exception)
