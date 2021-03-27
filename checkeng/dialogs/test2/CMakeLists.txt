project(Finish)
set(LIBRARY_NAME "test2dlg")

message("-- Configuring "  ${LIBRARY_NAME} " lib")

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_PATH})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_PATH})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_PATH})
set(TEST2_PATH ${APP_PATH}/dialogs/test2)

include_directories(${SRC_PATH})
include_directories(${APP_PATH})
include_directories(${TEST2_PATH})

add_definitions(-DTEST2_DIALOG_LIBRARY)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Multimedia REQUIRED)

set(HEADER_FILES
    ${TEST2_PATH}/test2.h
    ${TEST2_PATH}/test2_pch.h
    ${TEST2_PATH}/test2_global.h    
)
set(SOURCE_FILES
    ${TEST2_PATH}/test2.cpp
)
set(FORMS
    ${TEST2_PATH}/test2.ui
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
    Qt5::Multimedia
    finishdlg
)
