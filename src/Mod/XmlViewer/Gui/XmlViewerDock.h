#ifndef XMLVIEWERDOCK_H
#define XMLVIEWERDOCK_H

#include <QWidget>
#include <QTreeWidget>
#include <QPlainTextEdit>

#include <Gui/DockWindow.h>


namespace Gui
{
namespace DockWnd
{

class XmlTreeWidget: public QTreeWidget
{
    Q_OBJECT
public:
    explicit XmlTreeWidget(const char* name, QWidget* parent = nullptr);
    ~XmlTreeWidget() override;
};

class XmlTreePanel: public QWidget
{
    Q_OBJECT
public:
    explicit XmlTreePanel(const char* name, QWidget* parent = nullptr);
    ~XmlTreePanel() override;

private:
    XmlTreeWidget* treeWidget;
};

class XmlTextWidget: public QPlainTextEdit
{
    Q_OBJECT
public:
    explicit XmlTextWidget(const char* name, QWidget* parent = nullptr);
    ~XmlTextWidget() override;
};

class XmlTextPanel: public QWidget
{
    Q_OBJECT
public:
    explicit XmlTextPanel(const char* name, QWidget* parent = nullptr);
    ~XmlTextPanel() override;

private:
    XmlTextWidget* textWidget;
};

class XmlViewerDock: public Gui::DockWindow
{
    Q_OBJECT

public:
    XmlViewerDock(Gui::Document* pcDocument, QWidget* parent = nullptr);
    ~XmlViewerDock() override;

private:
    XmlTreePanel* tree;
    XmlTextPanel* data;
};

}  // namespace DockWnd
}  // namespace Gui
#endif  // XMLVIEWERDOCK_H