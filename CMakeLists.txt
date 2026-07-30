cmake_minimum_required(VERSION 3.21)

project(2048-qt
    VERSION 4.1
    DESCRIPTION "Single player 2d puzzle game"
    HOMEPAGE_URL "https://github.com/keshavbhatt/2048-qt"
    LANGUAGES CXX
)

set(APP_NAME "2048-qt")
set(APP_EXECUTABLE_NAME "2048-qt")
set(APP_GENERIC_NAME "2048")

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/src/2048.desktop.in"
    "${CMAKE_CURRENT_BINARY_DIR}/${APP_EXECUTABLE_NAME}.desktop"
    @ONLY
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Find Qt6
find_package(Qt6 6.2 REQUIRED COMPONENTS
    Core
    Gui
    Widgets
    WebEngineWidgets
    WebEngineCore
)

qt_standard_project_setup()

# Suppress qDebug output in non-debug builds.
add_compile_definitions(
    $<$<OR:$<CONFIG:Release>,$<CONFIG:RelWithDebInfo>,$<CONFIG:MinSizeRel>>:QT_NO_DEBUG_OUTPUT>
)

qt_add_executable(${APP_EXECUTABLE_NAME}
    src/main.cpp
    src/mainwindow.cpp
    src/mainwindow.h
    src/mainwindow.ui
    src/aboutdialog.cpp
    src/aboutdialog.h
    src/aboutdialog.ui
    src/urlrequestinterceptor.h
    src/res.qrc
    src/html.qrc
)

target_compile_definitions(${APP_EXECUTABLE_NAME} PRIVATE
    APPNAMESTR="${APP_NAME}"
    VERSIONSTR="${PROJECT_VERSION}"
)

target_link_libraries(${APP_EXECUTABLE_NAME} PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::WebEngineWidgets
    Qt6::WebEngineCore
)

# Embed Windows icon
if(WIN32)
    enable_language(RC)
    target_sources(${APP_EXECUTABLE_NAME} PRIVATE src/2048.rc)
    set_target_properties(${APP_EXECUTABLE_NAME} PROPERTIES WIN32_EXECUTABLE TRUE)
endif()

# Install rules
include(GNUInstallDirs)
install(TARGETS ${APP_EXECUTABLE_NAME} DESTINATION ${CMAKE_INSTALL_BINDIR})

if(NOT WIN32)
    install(FILES src/icon.png
        DESTINATION ${CMAKE_INSTALL_DATADIR}/icons/hicolor/512x512/apps
        RENAME ${APP_EXECUTABLE_NAME}.png
    )
    install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${APP_EXECUTABLE_NAME}.desktop"
        DESTINATION ${CMAKE_INSTALL_DATADIR}/applications
    )
endif()
