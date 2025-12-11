// SPDX-License-Identifier: LGPL-2.1-or-later

/***************************************************************************
 *   Copyright (c) YEAR YOUR NAME <Your e-mail address>                    *
 *                                                                         *
 *   This file is part of the FreeCAD CAx development system.              *
 *                                                                         *
 *   This library is free software; you can redistribute it and/or         *
 *   modify it under the terms of the GNU Library General Public           *
 *   License as published by the Free Software Foundation; either          *
 *   version 2 of the License, or (at your option) any later version.      *
 *                                                                         *
 *   This library  is distributed in the hope that it will be useful,      *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU Library General Public License for more details.                  *
 *                                                                         *
 *   You should have received a copy of the GNU Library General Public     *
 *   License along with this library; see the file COPYING.LIB. If not,    *
 *   write to the Free Software Foundation, Inc., 59 Temple Place,         *
 *   Suite 330, Boston, MA  02111-1307, USA                                *
 *                                                                         *
 ***************************************************************************/
#include <string>
#include "ComboView.h"

#include <App/Document.h>
#include <Base/Console.h>
#include <Gui/Application.h>
#include <Gui/Command.h>

#include "MainWindow.h"
#include "DockWindowManager.h"
#include "OverlayManager.h"
#include "XmlViewerDock.h"


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//===========================================================================
// CmdXmlViewerTest THIS IS JUST A TEST COMMAND
//===========================================================================
DEF_STD_CMD(CmdXmlViewerTest)

CmdXmlViewerTest::CmdXmlViewerTest()
    : Command("XmlViewer_Test")
{
    sAppModule = "XmlViewer";
    sGroup = QT_TR_NOOP("XmlViewer");
    sMenuText = QT_TR_NOOP("Hello");
    sToolTipText = QT_TR_NOOP("XmlViewer Test function");
    sWhatsThis = "XmlViewer_Test";
    sStatusTip = QT_TR_NOOP("XmlViewer Test function");
    sPixmap = "XmlViewerWorkbench";
    sAccel = "CTRL+H";
}

void CmdXmlViewerTest::activated(int)
{
    Base::Console().message("Hello, World!\n");
}

DEF_STD_CMD(CmdXmlViewerDialog)
CmdXmlViewerDialog::CmdXmlViewerDialog()
    : Command("XmlViewer_Dialog")
{
    sAppModule = "XmlViewer";
    sGroup = QT_TR_NOOP("XmlViewer");
    sMenuText = QT_TR_NOOP("Show Dialog");
    sToolTipText = QT_TR_NOOP("Show XmlViewer Dialog");
    sWhatsThis = "XmlViewer_Dialog";
    sStatusTip = QT_TR_NOOP("XmlViewer Show Dialog Function");
    sPixmap = "XmlViewerWorkbench";
    sAccel = "CTRL+D";
}

void CmdXmlViewerDialog::activated(int)
{
    // TODO: implement dialog show;
    Base::Console().message("Show XmlViewer Dialog\n");
    bool enabled = true;  // get from config
    std::string name = "XmlViewer_DockWindow";
    bool show = true;  // get from config
    // update xml viewer dialog

    auto pDockMgr = Gui::DockWindowManager::instance();
    auto widget = pDockMgr->findRegisteredDockWindow(name.data());
    if (!enabled) {
        if (widget) {
            pDockMgr->removeDockWindow(widget);
            pDockMgr->unregisterDockWindow(name.data());
            widget->deleteLater();
        }
        return;
    }

    auto pcComboView = new Gui::DockWnd::XmlViewerDock(nullptr, Gui::getMainWindow());
    //auto pcComboView = new Gui::DockWnd::ComboView(nullptr, Gui::getMainWindow());
    pcComboView->setObjectName(QStringLiteral("Xml Data"));
    pcComboView->setWindowTitle(QDockWidget::tr("Xml Data"));
    pcComboView->setMinimumWidth(150);
    widget = pcComboView;

    if (!widget) {
        return;
    }

    Gui::DockWindowManager::instance()->registerDockWindow(name.data(), widget);
    if (show) {
        auto dock = pDockMgr->addDockWindow(
            widget->objectName().toUtf8().constData(),
            widget,
            Qt::DockWidgetArea::RightDockWidgetArea
        );
        if (dock) {
            if (!dock->toggleViewAction()->isChecked()) {
                dock->toggleViewAction()->activate(QAction::Trigger);
            }
            Gui::OverlayManager::instance()->refresh(dock);
        }
    }
    
    // TODO: load current document xml cache to dialog;
}

DEF_STD_CMD(CmdXmlViewerRefersh)

CmdXmlViewerRefersh::CmdXmlViewerRefersh()
    : Command("XmlViewer_Refersh")
{
    sAppModule = "XmlViewer";
    sGroup = QT_TR_NOOP("XmlViewer");
    sMenuText = QT_TR_NOOP("Refersh");
    sToolTipText = QT_TR_NOOP("Refresh Current Document Xml");
    sWhatsThis = "XmlViewer_Refersh";
    sStatusTip = QT_TR_NOOP("XmlViewer Refresh Function");
    sPixmap = "XmlViewerWorkbench";
    sAccel = "CTRL+F";
}

void CmdXmlViewerRefersh::activated(int)
{
    Base::Console().message("Refersh Document xml");
}

void CreateXmlViewerCommands(void)
{
    Gui::CommandManager& rcCmdMgr = Gui::Application::Instance->commandManager();
    rcCmdMgr.addCommand(new CmdXmlViewerTest());
    rcCmdMgr.addCommand(new CmdXmlViewerRefersh());
    rcCmdMgr.addCommand(new CmdXmlViewerDialog());
}
