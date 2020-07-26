cmake_minimum_required(VERSION 3.5)

project(TowerDefense LANGUAGES CXX VERSION 0.0.1)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

file(GLOB SOURCES
    ./src/*.cpp
    ./src/*.h
    ./src/*.qrc
)

find_package(Qt5 COMPONENTS Gui Widgets Core Multimedia REQUIRED)


add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} Qt5::Gui Qt5::Widgets Qt5::Core Qt5::Multimedia)
