# SPDX-License-Identifier: LGPL-2.1-or-later

include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_CURRENT_BINARY_DIR}
)

set(XmlViewerGui_LIBS
    XmlViewer
    FreeCADGui
)

qt_add_resources(XmlViewer_QRC_SRCS Resources/XmlViewer.qrc)

SET(XmlViewerGui_SRCS
    ${XmlViewer_QRC_SRCS}
    AppXmlViewerGui.cpp
    Command.cpp
    PreCompiled.h
    Workbench.cpp
    Workbench.h
    XmlViewerDock.cpp
    XmlViewerDock.h
)

add_library(XmlViewerGui SHARED ${XmlViewerGui_SRCS})
target_link_libraries(XmlViewerGui ${XmlViewerGui_LIBS})

SET_BIN_DIR(XmlViewerGui XmlViewerGui /Mod/XmlViewer)
SET_PYTHON_PREFIX_SUFFIX(XmlViewerGui)

install(TARGETS XmlViewerGui DESTINATION ${CMAKE_INSTALL_LIBDIR})
