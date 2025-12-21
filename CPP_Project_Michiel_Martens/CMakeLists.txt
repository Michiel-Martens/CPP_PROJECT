cmake_minimum_required(VERSION 3.16)

project(NEWtestCPP_PJ LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(NEWtestCPP_PJ
  main.cpp
  PlayerBase.h
  PlayerBase.cpp
  HumanPlayer.h
  HumanPlayer.cpp
  AIPlayer.h
  AIPlayer.cpp
  Game.h
  Game.cpp
  Card.h
  Deck.h
  Card.cpp
  Deck.cpp
)
target_link_libraries(NEWtestCPP_PJ Qt${QT_VERSION_MAJOR}::Core)

include(GNUInstallDirs)
install(TARGETS NEWtestCPP_PJ
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
