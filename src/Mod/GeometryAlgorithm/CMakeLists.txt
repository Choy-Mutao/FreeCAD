# SPDX-License-Identifier: LGPL-2.1-or-later

add_subdirectory(App)
if(BUILD_GUI)
    add_subdirectory(Gui)
endif(BUILD_GUI)

set(GeometryAlgorithm_Scripts
    Init.py
)

if(BUILD_GUI)
    list (APPEND GeometryAlgorithm_Scripts InitGui.py)
endif(BUILD_GUI)

add_custom_target(GeometryAlgorithmScripts ALL
    SOURCES ${GeometryAlgorithm_Scripts}
)

fc_target_copy_resource_flat(GeometryAlgorithmScripts
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_BINARY_DIR}/Mod/GeometryAlgorithm
    ${GeometryAlgorithm_Scripts}
)

install(
    FILES
        ${GeometryAlgorithm_Scripts}
    DESTINATION
        Mod/GeometryAlgorithm
)
