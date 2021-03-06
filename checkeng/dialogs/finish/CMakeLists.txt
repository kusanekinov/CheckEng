project(Finish)
set(LIBRARY_NAME "finishdlg")

message("-- Configuring "  ${LIBRARY_NAME} " lib")

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_PATH})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_PATH})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_PATH})
set(FINISH_PATH ${APP_PATH}/dialogs/finish)

include_directories(${SRC_PATH})
include_directories(${APP_PATH})
include_directories(${FINISH_PATH})

add_definitions(-DFINISH_DIALOG_LIBRARY)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)

set(HEADER_FILES
    ${FINISH_PATH}/finish.h
    ${FINISH_PATH}/finish_pch.h
    ${FINISH_PATH}/finish_global.h    
)
set(SOURCE_FILES
    ${FINISH_PATH}/finish.cpp
)
set(FORMS
    ${FINISH_PATH}/finish.ui
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
)
