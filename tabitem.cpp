#include "tabitem.h"

#include <QPlainTextEdit>
#include <QFile>
#include <QTextStream>

TabItem::TabItem(const QString& filename, QWidget *parent) :
    QPlainTextEdit(parent)
{
    setReadOnly(true);

    loadFile(filename);
}

 void TabItem::loadFile(const QString& filename)
 {
     QFile file(filename);
     file.open(QIODevice::ReadOnly | QIODevice::Text);

     QTextStream in(&file);
     QString line;

     while (!in.atEnd()) {
         line = in.readLine();
         appendPlainText(line);
     }
 }
