cmake_minimum_required(VERSION 3.26)
project(log_analyser)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(log_analyser
        Lecture.cpp
        Lecture.h
        main.cpp
        Infos.cpp
        Infos.h
        Statistic.cpp
        Statistic.h
        InfosStorage.cpp
        InfosStorage.h)
