#include "mainwindow.h"

#include <QFileDialog>
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

    // Define actions
    m_actOpenfile = new QAction(tr("&Open a file"), this);
    m_actExit = new QAction(tr("&Quit"), this);

    // Add actions to file menu
    m_fileMenu->addAction(m_actOpenfile);
    m_fileMenu->addAction(m_actExit);

    // Add menus to the menu bar
    m_menuBar->addMenu(m_fileMenu);

    // Bind actions
    connect(m_actOpenfile, SIGNAL(triggered()), this, SLOT(openFilesDialog()));
    connect(m_actExit, SIGNAL(triggered()), this, SLOT(close()));

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
    auto fd = new QFileDialog();
    fd->setFileMode(QFileDialog::ExistingFile);
    fd->setViewMode(QFileDialog::Detail);
    auto result = fd->exec();

    QStringList selectedFiles;
    if (result) {
        selectedFiles = fd->selectedFiles();
        for (QString filename : selectedFiles) {
            openFile(filename);
        }
    }
}

void MainWindow::openFile(const QString& filename)
{
    auto newTab = new TabItem(filename);
    m_tabs->addTab(newTab, filename);
}
