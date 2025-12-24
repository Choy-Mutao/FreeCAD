# SPDX-License-Identifier: LGPL-2.1-or-later

include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_CURRENT_BINARY_DIR}
)

set(GeometryAlgorithmGui_LIBS
    GeometryAlgorithm
    FreeCADGui
)

qt_add_resources(GeometryAlgorithm_QRC_SRCS Resources/GeometryAlgorithm.qrc)

SET(GeometryAlgorithmGui_SRCS
    ${GeometryAlgorithm_QRC_SRCS}
    AppGeometryAlgorithmGui.cpp
    Command.cpp
    PreCompiled.h
    Workbench.cpp
    Workbench.h
)

add_library(GeometryAlgorithmGui SHARED ${GeometryAlgorithmGui_SRCS})
target_link_libraries(GeometryAlgorithmGui pga ${GeometryAlgorithmGui_LIBS})


SET_BIN_DIR(GeometryAlgorithmGui GeometryAlgorithmGui /Mod/GeometryAlgorithm)
SET_PYTHON_PREFIX_SUFFIX(GeometryAlgorithmGui)

install(TARGETS GeometryAlgorithmGui DESTINATION ${CMAKE_INSTALL_LIBDIR})
