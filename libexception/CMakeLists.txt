cmake_minimum_required(VERSION 3.18)
project(Exception VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)


set(SOURCE_FILES 
src/ExceptionCore.h
src/Display.h
src/ExceptionModule.h
src/DisplayMessage.h
src/MessageIcon.h
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

install(TARGETS ${PROJECT_NAME} EXPORT ExceptionTargets DESTINATION lib)

install(FILES src/ExceptionModule.h
              src/DisplayMessage.h
              src/MessageIcon.h
              src/ExceptionCore.h
        DESTINATION include)

install(EXPORT ExceptionTargets FILE ExceptionTargets.cmake DESTINATION lib/cmake/Exception)
export(EXPORT ExceptionTargets FILE "${CMAKE_CURRENT_BINARY_DIR}/ExceptionTargets.cmake")
        
include(CMakePackageConfigHelpers)

# Generate the config file from the template (if you have a template)
# configure_file(ExceptionConfig.cmake.in ExceptionConfig.cmake @ONLY)

# Generate the config file without a template
write_basic_package_version_file(
  ExceptionConfigVersion.cmake
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY AnyNewerVersion
)

install(FILES
  ExceptionConfig.cmake
  "${CMAKE_CURRENT_BINARY_DIR}/ExceptionConfigVersion.cmake"
  DESTINATION lib/cmake/Exception
)

install(EXPORT ExceptionTargets
  FILE ExceptionTargets.cmake
  NAMESPACE Exception::
  DESTINATION lib/cmake/Exception
)
