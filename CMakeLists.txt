cmake_minimum_required(VERSION 3.5)

project(QFRCScouter VERSION 0.1 LANGUAGES CXX)
set(CMAKE_AUTOUIC_SEARCH_PATHS "ui/")

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets Svg)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Svg)

set(QRCODE_SOURCES
        Qt-QrCodeGenerator/src/QrCodeGenerator.cpp
        Qt-QrCodeGenerator/src/QrCodeGenerator.h
        Qt-QrCodeGenerator/src/qrcodegen/qrcodegen.cpp
        Qt-QrCodeGenerator/src/qrcodegen/qrcodegen.h)

set(PROJECT_SOURCES
        src/main.cpp
        src/MainWindow.cpp

        src/WelcomePage.cpp
        src/TeamInfo.cpp
        src/AutoScouting.cpp

        # ================== #
        include/MainWindow.h

        include/WelcomePage.h
        include/TeamInfo.h
        include/AutoScouting.h

        # ================== #
        ui/MainWindow.ui

        ui/WelcomePage.ui
        ui/TeamInfo.ui
        ui/AutoScouting.ui

        include/TeleScouting.h src/TeleScouting.cpp ui/TeleScouting.ui
        include/QRCode.h src/QRCode.cpp ui/QRCode.ui
)

qt_add_executable(QFRCScouter
    MANUAL_FINALIZATION
    ${QRCODE_SOURCES}
    ${PROJECT_SOURCES}
    include/BetterSpinBox.h src/BetterSpinBox.cpp ui/BetterSpinBox.ui


)

target_link_libraries(QFRCScouter PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Svg)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.QFRCScouter)
endif()
set_target_properties(QFRCScouter PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS QFRCScouter
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

target_include_directories(QFRCScouter PRIVATE include/)
target_include_directories(QFRCScouter PRIVATE Qt-QrCodeGenerator/src)


if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(QFRCScouter)
endif()
