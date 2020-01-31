cmake_minimum_required(VERSION 3.1)

project(FinDir LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Qml REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Sql REQUIRED)

set(FinDir_src
# addnew Window
addnew.h
addnew.cpp
addnew.ui
# auth Window
auth.h
auth.cpp
auth.ui
# converter Window
converter.h
converter.cpp
converter.ui
# mainwindow Window
mainwindow.h
mainwindow.cpp
mainwindow.ui
# stonks Window
stonks.h
stonks.cpp
stonks.ui
# Main
main.cpp
)

add_executable(FinDir ${FinDir_src})
target_compile_definitions(${PROJECT_NAME} PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(FinDir Qt5::Widgets)
target_link_libraries(FinDir Qt5::Core)
target_link_libraries(FinDir Qt5::Sql)
