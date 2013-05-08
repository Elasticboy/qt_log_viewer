#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QTableWidget>
#include <QString>

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

private:
    void initMenu();
    void initLayout();
    void openFile(const QString& filename);

    QVBoxLayout *m_vLayout;
    QMenuBar* m_menuBar;
    QMenu * m_fileMenu;
    QMenu * m_viewMenu;
    QAction * m_actOpen;
    QAction * m_actExit;
    QAction * m_actZoomIn;
    QAction * m_actZoomOut;

    QTabWidget* m_tabs;
    
signals:
    
public slots:
    void openFilesDialog();
    void zoomIn();
    void zoomOut();
    
};

#endif // MAINWINDOW_H
