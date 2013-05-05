#ifndef TABITEM_H
#define TABITEM_H

#include <QPlainTextEdit>
#include <QString>

class TabItem : public QPlainTextEdit
{
    Q_OBJECT
public:
    explicit TabItem(const QString& filename, QWidget *parent = 0);

private:
    void loadFile(const QString& filename);

signals:

public slots:

};

#endif // TABITEM_H
