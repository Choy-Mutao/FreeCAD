# SPDX-License-Identifier: LGPL-2.1-or-later

# XmlViewer gui init module
# (c) 2001 Juergen Riegel LGPL


class XmlViewerWorkbench(Workbench):
    "XmlViewer workbench object"

    MenuText = "XmlViewer"
    ToolTip = "XmlViewer workbench"

    def Initialize(self):
        # load the module
        import XmlViewerGui

    def GetClassName(self):
        return "XmlViewerGui::Workbench"


Gui.addWorkbench(XmlViewerWorkbench())
