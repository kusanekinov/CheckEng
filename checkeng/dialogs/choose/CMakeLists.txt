project(Choose)
set(LIBRARY_NAME "choosesdlg")

message("-- Configuring "  ${LIBRARY_NAME} " lib")

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_PATH})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_PATH})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_PATH})
set(CHOOSE_PATH ${APP_PATH}/dialogs/choose)

include_directories(${SRC_PATH})
include_directories(${APP_PATH})
include_directories(${ADD_TASKS_PATH})

add_definitions(-DCHOOSE_DIALOG_LIBRARY)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)

set(HEADER_FILES
    ${CHOOSE_PATH}/choose.h
    ${CHOOSE_PATH}/choose_pch.h
    ${CHOOSE_PATH}/choose_global.h    
)
set(SOURCE_FILES
    ${CHOOSE_PATH}/choose.cpp    
    ${APP_PATH}/login/login.cpp
)
set(FORMS
    ${CHOOSE_PATH}/choose.ui
)
qt5_wrap_ui(UI_FILES
    ${FORMS}
)
add_library(${LIBRARY_NAME} SHARED
    ${HEADER_FILES}
    ${SOURCE_FILES}
    ${UI_FILES}
    ${RESOURCES_FILES}
    ${FORMS}
)
target_link_libraries(${LIBRARY_NAME}
    Qt5::Widgets
    Qt5::Gui
    addtasksdlg
    addtasks2dlg
    test1dlg
    test2dlg
)
