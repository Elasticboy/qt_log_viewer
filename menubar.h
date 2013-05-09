#ifndef MENUBAR_H
#define MENUBAR_H

#include <QMenuBar>
#include <QMenu>
#include <QAction>

class MenuBar : public QMenuBar
{
    Q_OBJECT
public:
    explicit MenuBar(QWidget *parent = 0);
    
private:
    void initFileMenu();
    void initViewMenu();

    QMenu * m_menuFile;
    QMenu * m_menuView;

    QAction * m_actionOpen;
    QAction * m_actionCloseTab;
    QAction * m_actionQuit;

    QAction * m_actionZoomIn;
    QAction * m_actionZoomOut;

signals:
    void openTriggered();
    void closeTabTriggered();
    void quitTriggered();

    void zoomInTriggered();
    void zoomOutTriggered();
    
public slots:
    
};

#endif // MENUBAR_H
