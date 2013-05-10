#ifndef TABITEM_H
#define TABITEM_H

#include <QPlainTextEdit>
#include <QString>
#include <QWheelEvent>

class TabItem : public QPlainTextEdit
{
    Q_OBJECT
public:
    explicit TabItem(const QString& filename, QWidget *parent = 0);

    QString label() const { return m_label; }
    void setZoom(const int& step);

protected:
    virtual void wheelEvent(QWheelEvent* event);

private:
    void loadFile(const QString& filename);

    QString m_label;

signals:

public slots:

};

#endif // TABITEM_H
