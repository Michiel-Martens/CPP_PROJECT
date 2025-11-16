cmake_minimum_required(VERSION 3.16)

project(Chinees_Poepen_CPP_Project LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(Chinees_Poepen_CPP_Project
  main.cpp
  Card.h
  Card.cpp
  Deck.cpp
  Deck.h
  Player.cpp
  Player.h
  Game.h
  Game.cpp
)
target_link_libraries(Chinees_Poepen_CPP_Project Qt${QT_VERSION_MAJOR}::Core)

include(GNUInstallDirs)
install(TARGETS Chinees_Poepen_CPP_Project
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
