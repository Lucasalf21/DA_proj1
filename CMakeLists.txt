cmake_minimum_required(VERSION 3.27)
project(proj1_2324)

set(CMAKE_CXX_STANDARD 17)

add_executable(proj1_2324 src/main.cpp
        src/FileReader.h
        src/FileReader.cpp
        src/City.h
        src/City.cpp
        src/Pipe.h
        src/Pipe.cpp
        src/Reservoir.h
        src/Reservoir.cpp
        src/Station.h
        src/Station.cpp
        src/Menu.h
        src/Menu.cpp
        src/Graph.h
        src/Data.h
        src/Data.cpp
        src/GraphLoader.h
        src/GraphLoader.cpp
        src/SystemManager.h
        src/SystemManager.cpp
)
