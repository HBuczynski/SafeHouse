# Specify the minimum version of cmake.
cmake_minimum_required(VERSION 3.0)

project(peripherals)

set(PROJECT_NAME peripherals)
include_directories("../")
include_directories("../../3rd_party")

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

file(GLOB pigpio_source_list "../../3rd_party/PIGPIO/*.c")
file(GLOB pigpio_header_list "../../3rd_party/PIGPIO/*.h")

message("Found PIGPIO file list: ${pigpio_source_list} ${pigpio_header_list}")

add_library(PIGPIO STATIC ${pigpio_source_list} ${pigpio_header_list})

target_link_libraries(${PROJECT_NAME} LINK_PUBLIC config_reader)
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC protocol)
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC PIGPIO)

install(TARGETS ${PROJECT_NAME} DESTINATION lib OPTIONAL)
install(FILES ${header_list} DESTINATION include OPTIONAL)

if(BUILD_TESTS)
    add_subdirectory(unit_tests)
endif()