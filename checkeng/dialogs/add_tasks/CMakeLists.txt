project(AddTasks)
set(LIBRARY_NAME "addtasksdlg")

message("-- Configuring "  ${LIBRARY_NAME} " lib")

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_PATH})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_PATH})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_PATH})
set(ADD_TASKS_PATH ${APP_PATH}/dialogs/add_tasks)

include_directories(${SRC_PATH})
include_directories(${APP_PATH})
include_directories(${ADD_TASKS_PATH})

add_definitions(-DADD_TASKS_DIALOG_LIBRARY)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Network REQUIRED)

set(HEADER_FILES
    ${ADD_TASKS_PATH}/add_tasks.h
    ${ADD_TASKS_PATH}/add_tasks_pch.h
    ${ADD_TASKS_PATH}/add_tasks_global.h    
)
set(SOURCE_FILES
    ${ADD_TASKS_PATH}/add_tasks.cpp    
)
set(FORMS
    ${ADD_TASKS_PATH}/add_tasks.ui
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
    Qt5::Network
)
