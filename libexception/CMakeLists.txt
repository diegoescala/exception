cmake_minimum_required(VERSION 3.18)
project(libexception)

set(CMAKE_CXX_STANDARD 17)


set(SOURCE_FILES 
src/ExceptionCore.h
src/Display.h
src/ExceptionModule.h
src/DisplayMessage.h
src/MessageIcon.h
src/main.cpp
src/ExceptionModule.cpp
src/Display.cpp
src/MessageIcon.cpp
src/ExceptionCore.cpp
src/DisplayMessage.cpp
src/Timer.h
src/Timer.cpp
)

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads)