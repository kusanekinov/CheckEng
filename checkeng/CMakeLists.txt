cmake_minimum_required(VERSION 3.13)
project(checkeng LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets LinguistTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets LinguistTools REQUIRED)

set(APP_PATH ${CMAKE_CURRENT_LIST_DIR})

#set(TS_FILES en.ts)

add_subdirectory(dialogs)

set(LIBS
    aboutdlg
    finishdlg
)

add_executable(checkeng
    main.cpp
    main_window.cpp
    login/login.cpp
    main_window.h
    main_window.ui
    ${TS_FILES}
)

target_link_libraries(checkeng PRIVATE ${LIBS}
    Qt${QT_VERSION_MAJOR}::Widgets)

qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})

