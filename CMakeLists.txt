cmake_minimum_required(VERSION 3.27)
project(university_pjc)

set(CMAKE_CXX_STANDARD 20)
include(FetchContent)

FetchContent_Declare(
        fmt
        GIT_REPOSITORY  https://github.com/fmtlib/fmt
        GIT_TAG         10.2.1
)

FetchContent_MakeAvailable(fmt)


add_executable(PJC01_33 labs/lab_01/main.cpp
        labs/lab_01/main2.cpp
        labs/lab_01/main3.cpp
        labs/lab_02/main3.cpp)
