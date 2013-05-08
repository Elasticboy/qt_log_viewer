#include "mainwindow.h"

#include <QFileDialog>
#include <QPushButton>
#include "tabitem.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
    initMenu();
    initLayout();
}

void MainWindow::initMenu()
{
    m_menuBar = new QMenuBar();
    m_fileMenu = new QMenu(tr("File"), this);
    m_viewMenu = new QMenu(tr("View"), this);

    /**
      * File Menu
      */
    // Define actions
    m_actOpen   = new QAction(tr("&Open..."), this);
    m_actExit   = new QAction(tr("&Quit"), this);

    // Add actions
    m_fileMenu->addAction(m_actOpen);
    m_fileMenu->addAction(m_actExit);

    // Bind actions
    connect(m_actOpen, SIGNAL(triggered()), this, SLOT(openFilesDialog()));
    connect(m_actExit, SIGNAL(triggered()), this, SLOT(close()));

    // Add menus to the menu bar
    m_menuBar->addMenu(m_fileMenu);

    /**
      * View Menu
      */
    // Define actions
    m_actZoomIn     = new QAction(tr("Zoom in"), this);
    m_actZoomOut    = new QAction(tr("Zoom out"), this);

    // Add actions
    m_viewMenu->addAction(m_actZoomIn);
    m_viewMenu->addAction(m_actZoomOut);

    // Bind actions
    connect(m_actZoomIn, SIGNAL(triggered()), this, SLOT(openFilesDialog()));
    connect(m_actZoomOut, SIGNAL(triggered()), this, SLOT(close()));

    // Add menus to the menu bar
    m_menuBar->addMenu(m_viewMenu);

}

void MainWindow::initLayout()
{
    m_vLayout = new QVBoxLayout();

    m_tabs = new QTabWidget();
    m_vLayout->addWidget(m_tabs);

    m_vLayout->setMenuBar(m_menuBar);

    setLayout(m_vLayout);
}

void MainWindow::openFilesDialog()
{
    auto fileDialog = new QFileDialog(this);
    fileDialog->setFileMode(QFileDialog::ExistingFiles);
    fileDialog->setViewMode(QFileDialog::Detail);
    fileDialog->setFilter(QDir::Files);
    fileDialog->setNameFilter(tr("Log File (*.log *.txt)"));
    auto result = fileDialog->exec();

    QStringList selectedFiles;
    if (result) {
        selectedFiles = fileDialog->selectedFiles();
        for (QString filename : selectedFiles) {
            openFile(filename);
        }
    }
}

void MainWindow::openFile(const QString& filename)
{
    auto newTab = new TabItem(filename);
    const auto index = m_tabs->addTab(newTab, newTab->label());

    auto close = new QPushButton(this);
    m_tabs->tabBar()->setTabButton(index, QTabBar::RightSide, close);
}

void MainWindow::zoomIn()
{
    // TODO: Zoom in
}

void MainWindow::zoomOut()
{
    // TODO: Zoom out
}
