project(WeatherModule)

add_library(${PROJECT_NAME} SHARED src/WeatherModule.cpp src/WeatherModule.h)

message(${CMAKE_CURRENT_SOURCE_DIR})
find_package(Exception 1.0.0 REQUIRED PATHS ../../build/lib/cmake/Exception)

target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_BINARY_DIR}/../../include")

target_link_libraries(${PROJECT_NAME} PRIVATE Exception)
