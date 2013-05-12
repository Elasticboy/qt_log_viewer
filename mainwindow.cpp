#include "mainwindow.h"

#include <QFileDialog>
#include <QPushButton>
#include <memory>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    initMenu();
    initLayout();
}

MainWindow::~MainWindow()
{
    delete(m_tabs);
    m_tabs = nullptr;
    delete(m_menuBar);
    m_menuBar = nullptr;
}

void MainWindow::initMenu()
{
    m_menuBar = new MenuBar();

    // Bind actions
    connect(m_menuBar, SIGNAL(openTriggered()),     this, SLOT(openFilesDialog()));
    connect(m_menuBar, SIGNAL(closeTabTriggered()), this, SLOT(closeCurrentTab()));
    connect(m_menuBar, SIGNAL(quitTriggered()),     this, SLOT(close()));

    connect(m_menuBar, SIGNAL(zoomInTriggered()),   this, SLOT(zoomIn()));
    connect(m_menuBar, SIGNAL(zoomOutTriggered()),  this, SLOT(zoomOut()));

    setMenuBar(m_menuBar);
}

void MainWindow::initLayout()
{
    resize(600, 400);

    m_tabs = new QTabWidget();
    m_tabs->setTabsClosable(true);
    connect(m_tabs, SIGNAL(tabCloseRequested(int)), this, SLOT(closeTab(int)));

    setCentralWidget(m_tabs);
}

TabItem* MainWindow::currentTab() const
{
    return static_cast<TabItem*>(m_tabs->currentWidget());
}

void MainWindow::openFilesDialog()
{
    auto fileDialog = std::unique_ptr<QFileDialog>(new QFileDialog(this));

    fileDialog->setFileMode(QFileDialog::ExistingFiles);
    fileDialog->setViewMode(QFileDialog::Detail);
    fileDialog->setFilter(QDir::Files);
    fileDialog->setNameFilter(tr("Log File (*.log *.txt)"));
    auto result = fileDialog->exec();

    QStringList selectedFiles;
    if (result) {
        selectedFiles = fileDialog->selectedFiles();
        for (QString filename : selectedFiles) {
            newTab(filename);
        }
    }
}

void MainWindow::newTab(const QString& filename)
{
    auto newTab = new TabItem(filename);
    m_tabs->addTab(newTab, newTab->label());
}

void MainWindow::closeTab(const int& index)
{
    if (index == -1) {
        return;
    }

    auto tabItem = m_tabs->widget(index);
    m_tabs->removeTab(index);

    delete(tabItem);
    tabItem = nullptr;
}

void MainWindow::closeCurrentTab()
{
    closeTab(m_tabs->currentIndex());
}

void MainWindow::zoomIn()
{
    // TODO: Zoom in
    setZoom(1);
}

void MainWindow::zoomOut()
{
    // TODO: Zoom out
    setZoom(-1);
}

void MainWindow::setZoom(const int& step)
{
    auto tab = currentTab();
    if (tab) {
        tab->setZoom(step);
    }
}
