#include "mainwindow.h"

#include <QFileDialog>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
    initMenu();
    initLayout();
}

void MainWindow::initMenu()
{
    m_menuBar = new MenuBar();

    // Bind actions
    connect(m_menuBar, SIGNAL(openTriggered()),     this, SLOT(openFilesDialog()));
    connect(m_menuBar, SIGNAL(closeTabTriggered()), this, SLOT(closeTab()));
    connect(m_menuBar, SIGNAL(quitTriggered()),     this, SLOT(close()));

    connect(m_menuBar, SIGNAL(zoomInTriggered()),   this, SLOT(zoomIn()));
    connect(m_menuBar, SIGNAL(zoomOutTriggered()),  this, SLOT(zoomOut()));
}

void MainWindow::initLayout()
{
    m_vLayout = new QVBoxLayout();
    m_vLayout->setContentsMargins(0, 0, 0, 0);

    m_tabs = new QTabWidget();

    m_vLayout->addWidget(m_tabs);
    m_vLayout->setMenuBar(m_menuBar);

    setLayout(m_vLayout);
}

TabItem* MainWindow::currentTab() const
{
    return static_cast<TabItem*>(m_tabs->currentWidget());
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
            newTab(filename);
        }
    }
}

void MainWindow::newTab(const QString& filename)
{
    auto newTab = new TabItem(filename);
    const auto index = m_tabs->addTab(newTab, newTab->label());

    auto closeBtn = new QPushButton(this);
    m_tabs->tabBar()->setTabButton(index, QTabBar::RightSide, closeBtn);
}

void MainWindow::closeTab()
{
    const auto currentIndex = m_tabs->currentIndex();
    if (currentIndex != -1) {
        m_tabs->removeTab(currentIndex);
    }

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
