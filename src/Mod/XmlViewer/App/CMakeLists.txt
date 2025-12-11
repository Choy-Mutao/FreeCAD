# SPDX-License-Identifier: LGPL-2.1-or-later

set(XmlViewer_LIBS
    FreeCADApp
)

SET(XmlViewer_SRCS
    AppXmlViewer.cpp
    PreCompiled.h
)

add_library(XmlViewer SHARED ${XmlViewer_SRCS})
target_link_libraries(XmlViewer ${XmlViewer_LIBS})


SET_BIN_DIR(XmlViewer XmlViewer /Mod/XmlViewer)
SET_PYTHON_PREFIX_SUFFIX(XmlViewer)

install(TARGETS XmlViewer DESTINATION ${CMAKE_INSTALL_LIBDIR})
