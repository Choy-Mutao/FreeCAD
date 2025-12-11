#include "XmlViewerDock.h"
#include <QGridLayout>
#include <QSplitter>

Gui::DockWnd::XmlViewerDock::XmlViewerDock(Gui::Document* pcDocument, QWidget* parent)
{
    auto pLayout = new QGridLayout(this);
    pLayout->setSpacing(0);
    pLayout->setContentsMargins(0, 0, 0, 0);

    auto splitter = new QSplitter();
    pLayout->addWidget(splitter, 0, 0);

    splitter->setOrientation(Qt::Vertical);

    tree = new XmlTreePanel("Files", this);
    splitter->addWidget(tree);

    data = new XmlTextPanel("Data", this);
    splitter->addWidget(data);
}

Gui::DockWnd::XmlViewerDock::~XmlViewerDock() = default;

Gui::DockWnd::XmlTreePanel::XmlTreePanel(const char* name, QWidget* parent)
    : QWidget(parent)
{
    this->treeWidget = new XmlTreeWidget(name, this);
}

Gui::DockWnd::XmlTreePanel::~XmlTreePanel() = default;

Gui::DockWnd::XmlTreeWidget::XmlTreeWidget(const char* name, QWidget* parent)
    : QTreeWidget(parent)
{}

Gui::DockWnd::XmlTreeWidget::~XmlTreeWidget()
{
    /*connectNewDocument.disconnect();
    connectDelDocument.disconnect();
    connectRenDocument.disconnect();
    connectActDocument.disconnect();
    connectRelDocument.disconnect();
    connectShowHidden.disconnect();
    connectChangedViewObj.disconnect();
    Instances.erase(this);
    if (_LastSelectedTreeWidget == this) {
        _LastSelectedTreeWidget = nullptr;
    }*/
}

Gui::DockWnd::XmlTextPanel::XmlTextPanel(const char* name, QWidget* parent)
    : QWidget(parent)
{
    this->textWidget = new XmlTextWidget(name, this);
}

Gui::DockWnd::XmlTextPanel::~XmlTextPanel() = default;

Gui::DockWnd::XmlTextWidget::XmlTextWidget(const char* name, QWidget* parent)
    : QPlainTextEdit(parent)
{}

Gui::DockWnd::XmlTextWidget::~XmlTextWidget()
{
}
