# SPDX-License-Identifier: LGPL-2.1-or-later

add_subdirectory(App)
if(BUILD_GUI)
    add_subdirectory(Gui)
endif(BUILD_GUI)

set(XmlViewer_Scripts
    Init.py
)

if(BUILD_GUI)
    list (APPEND XmlViewer_Scripts InitGui.py)
endif(BUILD_GUI)

add_custom_target(XmlViewerScripts ALL
    SOURCES ${XmlViewer_Scripts}
)

fc_target_copy_resource_flat(XmlViewerScripts
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_BINARY_DIR}/Mod/XmlViewer
    ${XmlViewer_Scripts}
)

install(
    FILES
        ${XmlViewer_Scripts}
    DESTINATION
        Mod/XmlViewer
)
