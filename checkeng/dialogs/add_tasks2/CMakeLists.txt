project(AddTasks2)
set(LIBRARY_NAME "addtasks2dlg")

message("-- Configuring "  ${LIBRARY_NAME} " lib")

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_PATH})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_PATH})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_PATH})
set(ADD_TASKS2_PATH ${APP_PATH}/dialogs/add_tasks2)

include_directories(${SRC_PATH})
include_directories(${APP_PATH})
include_directories(${ADD_TASKS2_PATH})

add_definitions(-DADD_TASKS2_DIALOG_LIBRARY)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Network REQUIRED)

set(HEADER_FILES
    ${ADD_TASKS2_PATH}/add_tasks2.h
    ${ADD_TASKS2_PATH}/add_tasks2_pch.h
    ${ADD_TASKS2_PATH}/add_tasks2_global.h    
)
set(SOURCE_FILES
    ${ADD_TASKS2_PATH}/add_tasks2.cpp    
)
set(FORMS
    ${ADD_TASKS2_PATH}/add_tasks2.ui
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
