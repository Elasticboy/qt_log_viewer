#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QString>
#include "menubar.h"

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

private:
    void initMenu();
    void initLayout();
    void newTab(const QString& filename);
    void setZoom(const int& step);

    QVBoxLayout *m_vLayout;
    MenuBar* m_menuBar;

    QTabWidget* m_tabs;
    
signals:
    
public slots:
    void openFilesDialog();
    void closeTab();
    void zoomIn();
    void zoomOut();
    
};

#endif // MAINWINDOW_H
