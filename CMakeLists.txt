cmake_minimum_required(VERSION 3.0)
project(Progetto_Laboratorio_Programmazione)

set(CMAKE_CXX_STANDARD 11)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(Progetto_Laboratorio_Programmazione
        main.cpp
        Grid.cpp
        Grid.h
        Node.cpp
        Node.h
        PathFinder.cpp
        PathFinder.h
)

target_link_libraries(Progetto_Laboratorio_Programmazione sfml-graphics sfml-window sfml-system)