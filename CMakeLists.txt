cmake_minimum_required(VERSION 3.9)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(exceptionapp)

set ( CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_BINARY_DIR} CACHE PATH "Install directory" FORCE)
message (STATUS "CMAKE_INSTALL_PREFIX: ${CMAKE_INSTALL_PREFIX}")

# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/out/lib)
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/out/bin)

add_subdirectory(libexception)
add_subdirectory(exception)
add_subdirectory(3rdParty/cpp-httplib)
add_subdirectory(modules/weather)

find_package(Doxygen)
if(DOXYGEN_FOUND)
	add_custom_target(doxy)
endif(DOXYGEN_FOUND)

if(MSVC11)
	add_definitions("-D_VARIADIC_MAX#10")
endif(MSVC11)


export(TARGETS exceptionapp Exception httplib
  FILE "${PROJECT_BINARY_DIR}/ExceptionTargets.cmake")

#target_compile_features(CamEngineModels PRIVATE cxx_std_17)
# set_property(TARGET CamEngineModels PROPERTY CXX_STANDARD 17)

export(PACKAGE ExceptionApp)

option (DEVELOPMENT_BUILD "Development / non-production build" FALSE)
  