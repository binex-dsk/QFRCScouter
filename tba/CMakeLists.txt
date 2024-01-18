cmake_minimum_required(VERSION 3.14)

project(ScheduleGenerator LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(ScheduleGenerator
  main.cpp
  Match.cpp
  Match.h

  Schedule.cpp
  Schedule.h

  ../src/MatchData.cpp
  ../include/MatchData.h
  ../Schedule.qrc
)
target_link_libraries(ScheduleGenerator Qt${QT_VERSION_MAJOR}::Core)

target_include_directories(ScheduleGenerator PRIVATE ./)
target_include_directories(ScheduleGenerator PRIVATE ../include/)


include(GNUInstallDirs)
install(TARGETS ScheduleGenerator
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
