cmake_minimum_required(VERSION 4.0)
project(tick_tack_toe_console)

set(CMAKE_CXX_STANDARD 14)

add_executable(tick_tack_toe_console
        Main.cpp
        Player.cpp
        Player.h
        Board.cpp
        Board.h)
