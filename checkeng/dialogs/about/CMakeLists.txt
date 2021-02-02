project(About)
set(LIBRARY_NAME "aboutdlg")

message("-- Configuring "  ${LIBRARY_NAME} " lib")

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_PATH})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_PATH})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_PATH})
set(ABOUT_PATH ${APP_PATH}/dialogs/about)

include_directories(${SRC_PATH})
include_directories(${APP_PATH})
include_directories(${ABOUT_PATH})

add_definitions(-DABOUT_DIALOG_LIBRARY)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)

set(HEADER_FILES
    ${ABOUT_PATH}/about.h
    ${ABOUT_PATH}/about_pch.h
    ${ABOUT_PATH}/about_global.h    
)
set(SOURCE_FILES
    ${ABOUT_PATH}/about.cpp    
)
set(FORMS
    ${ABOUT_PATH}/about.ui
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
