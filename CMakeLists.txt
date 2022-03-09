cmake_minimum_required(VERSION 3.21)
project(BlackJack)

set(CMAKE_CXX_STANDARD 14)
include_directories(./Card ./Helpers)
add_executable(BlackJack main.cpp Card/CardClass.cpp Card/CardClass.h Controller.cpp Controller.h Card/CardInfo.h Card/CardInfo.cpp Helpers/ConsoleHelpers.cpp Helpers/ConsoleHelpers.h)
