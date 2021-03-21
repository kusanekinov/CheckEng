project(Add_questions)
set(LIBRARY_NAME "add_questionsdlg")

message("-- Configuring "  ${LIBRARY_NAME} " lib")

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_PATH})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_PATH})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_PATH})
set(ABOUT_PATH ${APP_PATH}/dialogs/add_questions)

include_directories(${SRC_PATH})
include_directories(${APP_PATH})
include_directories(${ADD_QUESTIONS_PATH})

add_definitions(-DADD_QUESTIONS_DIALOG_LIBRARY)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)

set(HEADER_FILES
    ${ADD_QUESTIONS_PATH}/add_questions.h
    ${ADD_QUESTIONS_PATH}/add_questions_pch.h
    ${ADD_QUESTIONS_PATH}/add_questions_global.h    
)
set(SOURCE_FILES
    ${ADD_QUESTIONS_PATH}/add_questions.cpp    
)
set(FORMS
    ${ADD_QUESTIONS_PATH}/add_questions.ui
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
