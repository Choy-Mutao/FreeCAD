# SPDX-License-Identifier: LGPL-2.1-or-later

# GeometryAlgorithm gui init module
# (c) 2001 Juergen Riegel LGPL


class GeometryAlgorithmWorkbench(Workbench):
    "GeometryAlgorithm workbench object"

    MenuText = "GeometryAlgorithm"
    ToolTip = "GeometryAlgorithm workbench"

    def Initialize(self):
        # load the module
        import GeometryAlgorithmGui

    def GetClassName(self):
        return "GeometryAlgorithmGui::Workbench"


Gui.addWorkbench(GeometryAlgorithmWorkbench())
