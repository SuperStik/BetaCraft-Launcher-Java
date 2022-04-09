cmake_minimum_required(VERSION 3.16)

project(Betacraft VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets WebEngineWidgets WebEngineCore WebChannel)

add_executable(Betacraft
    MainWindow.cpp MainWindow.h
    main.cpp
    assets.qrc
)

target_link_libraries(Betacraft PRIVATE
    Qt6::Widgets
    Qt::WebEngineCore
    Qt::WebEngineWidgets
    Qt::WebChannel)
