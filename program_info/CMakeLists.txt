# Config stuff
if(UNIX AND NOT(APPLE))
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/QFRCScouter.desktop DESTINATION "share/applications")
    install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/QFRCScouter.svg DESTINATION "share/icons/hicolor/scalable/apps")
    install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/QFRCScouter.svg DESTINATION "share/icons/hicolor/symbolic/apps" RENAME QFRCScouter.svg)
endif()

configure_file(QFRCScouter.rc.in QFRCScouter.rc)
configure_file(QFRCScouter.manifest.in QFRCScouter.manifest)
configure_file(QFRCScouter.desktop.in QFRCScouter.desktop)
configure_file(QFRCScouter.ico QFRCScouter.ico COPYONLY)
