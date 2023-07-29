cmake_minimum_required(VERSION 3.16)

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_EXTENSIONS OFF)

PROJECT(DataStructureAndAlgorithm LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Quick)
qt_standard_project_setup()

add_subdirectory(DSA)
