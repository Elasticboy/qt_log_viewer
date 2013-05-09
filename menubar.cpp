#include "menubar.h"

MenuBar::MenuBar(QWidget *parent) :
    QMenuBar(parent)
{
    initFileMenu();
    initViewMenu();
}

/**
  * Initialize the File Menu
  */
void MenuBar::initFileMenu()
{
    m_menuFile = new QMenu(tr("File"), this);

    // Define actions
    m_actionOpen        = new QAction(tr("&Open..."), this);
    m_actionCloseTab    = new QAction(tr("Close tab"), this);
    m_actionQuit        = new QAction(tr("&Quit"), this);

    // Add actions
    m_menuFile->addAction(m_actionOpen);
    m_menuFile->addAction(m_actionCloseTab);
    m_menuFile->addAction(m_actionQuit);

    // Bind actions to signals
    connect(m_actionOpen,       SIGNAL(triggered()), this, SIGNAL(openTriggered()));
    connect(m_actionCloseTab,   SIGNAL(triggered()), this, SIGNAL(closeTabTriggered()));
    connect(m_actionQuit,       SIGNAL(triggered()), this, SIGNAL(quitTriggered()));

    // Add menu to the menu bar
    addMenu(m_menuFile);
}

/**
  * Initialize the View Menu
  */
void MenuBar::initViewMenu()
{
    m_menuView = new QMenu(tr("View"), this);

    // Define actions
    m_actionZoomIn  = new QAction(tr("Zoom in"), this);
    m_actionZoomIn->setShortcuts(QKeySequence::ZoomIn);
    m_actionZoomOut = new QAction(tr("Zoom out"), this);
    m_actionZoomOut->setShortcuts(QKeySequence::ZoomOut);

    // Add actions
    m_menuView->addAction(m_actionZoomIn);
    m_menuView->addAction(m_actionZoomOut);

    // Bind actions to signals
    connect(m_actionZoomIn,     SIGNAL(triggered()), this, SIGNAL(zoomInTriggered()));
    connect(m_actionZoomOut,    SIGNAL(triggered()), this, SIGNAL(zoomOutTriggered()));

    // Add menu to the menu bar
   addMenu(m_menuView);
}
