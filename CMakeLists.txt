cmake_minimum_required(VERSION 2.6)
add_definitions( -std=c++14 )
project(PaperRockShissor)
add_executable(game main.cpp tictactoe.cpp)
