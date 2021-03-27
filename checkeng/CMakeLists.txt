cmake_minimum_required(VERSION 3.16)
project(checkeng LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets LinguistTools  Network REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets LinguistTools Network REQUIRED)

set(APP_PATH ${CMAKE_CURRENT_LIST_DIR})
set(RESOURCES_PATH ${APP_PATH}/resources)
set(TRANSLATIONS_PATH ${APP_PATH})

#set(TS_FILES en.ts)

set(RESOURCES
    ${RESOURCES_PATH}/images/svg.qrc
    ${RESOURCES_PATH}/css/css.qrc
)
set(TranslationFiles
   ${TRANSLATIONS_PATH}/resources/langs/en.ts
   ${TRANSLATIONS_PATH}/resources/langs/ru.ts
)

qt5_add_resources(MOC_RESOURCES
    ${RESOURCES}
)

add_subdirectory(dialogs)

set(LIBS
    aboutdlg
    finishdlg
    addtasksdlg
    choosesdlg
    test1dlg
    test2dlg
    addtasks2dlg
)

add_executable(checkeng
    main.cpp
    main_window.cpp
    login/login.cpp

    main_window.ui
    ${MOC_RESOURCES}
    ${RESOURCES_PATH}/a.rc
    ${TS_FILES}
)

target_link_libraries(checkeng PRIVATE ${LIBS}
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Network
)

qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})

