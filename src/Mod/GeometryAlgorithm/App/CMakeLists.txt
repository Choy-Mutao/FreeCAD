# SPDX-License-Identifier: LGPL-2.1-or-later

set(GeometryAlgorithm_LIBS
    FreeCADApp
)

SET(GeometryAlgorithm_SRCS
    AppGeometryAlgorithm.cpp
    PreCompiled.h
)

add_library(GeometryAlgorithm SHARED ${GeometryAlgorithm_SRCS})
target_link_libraries(GeometryAlgorithm ${GeometryAlgorithm_LIBS})


SET_BIN_DIR(GeometryAlgorithm GeometryAlgorithm /Mod/GeometryAlgorithm)
SET_PYTHON_PREFIX_SUFFIX(GeometryAlgorithm)

install(TARGETS GeometryAlgorithm DESTINATION ${CMAKE_INSTALL_LIBDIR})
