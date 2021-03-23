project(Finish)
set(LIBRARY_NAME "test1dlg")

message("-- Configuring "  ${LIBRARY_NAME} " lib")

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_PATH})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_PATH})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_PATH})
set(TEST1_PATH ${APP_PATH}/dialogs/test1)

include_directories(${SRC_PATH})
include_directories(${APP_PATH})
include_directories(${TEST1_PATH})

add_definitions(-DTEST1_DIALOG_LIBRARY)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)

set(HEADER_FILES
    ${TEST1_PATH}/test1.h
    ${TEST1_PATH}/test1_pch.h
    ${TEST1_PATH}/test1_global.h    
)
set(SOURCE_FILES
    ${TEST1_PATH}/test1.cpp
)
set(FORMS
    ${TEST1_PATH}/test1.ui
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
    finishdlg
)
