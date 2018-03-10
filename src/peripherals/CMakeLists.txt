# Specify the minimum version of cmake.
cmake_minimum_required(VERSION 3.0)

project(peripherals)

set(PROJECT_NAME peripherals)
include_directories("../")

file(GLOB source_list "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
file(GLOB header_list "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

add_library(${PROJECT_NAME} ${source_list})

target_include_directories(
        ${PROJECT_NAME} PUBLIC
        # Headers used from source/build location:
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
        # Headers used from the installed location:
        "$<INSTALL_INTERFACE:include>"
)


target_link_libraries(${PROJECT_NAME} LINK_PUBLIC pigpio)
