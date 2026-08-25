cmake_minimum_required(VERSION 3.16)

project(SecureNOS
    VERSION 0.1.0
    DESCRIPTION "Security-focused Network Operating System"
    LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

message(STATUS "========================================")
message(STATUS "          SecureNOS Build System")
message(STATUS "========================================")
message(STATUS "Version      : ${PROJECT_VERSION}")
message(STATUS "C++ Standard : C++${CMAKE_CXX_STANDARD}")
message(STATUS "C Standard   : C${CMAKE_C_STANDARD}")
message(STATUS "========================================")

add_executable(securenos
    src/main.cpp
    src/system/system_manager.cpp
)

target_include_directories(securenos
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)
