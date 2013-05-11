#include "tabitem.h"

#include <QPlainTextEdit>
#include <QFile>
#include <QTextStream>
#include <QFileInfo>

TabItem::TabItem(const QString& filename, QWidget *parent) :
    QPlainTextEdit(parent)
{
    setReadOnly(true);

    // Set title
    QFileInfo fileInfo(filename);
    m_label = fileInfo.fileName();

    loadFile(filename);
}

void TabItem::wheelEvent(QWheelEvent* event)
{
    const auto degrees = event->angleDelta() / 8;
    const auto steps = degrees / 15;

    if (event->modifiers() == Qt::ControlModifier) {
        setZoom(steps.y());
    } else {
        QPlainTextEdit::wheelEvent(event);
    }
}

void TabItem::setZoom(const int& step)
{
    const auto MIN_FONT_SIZE = 6;
    const auto MAX_FONT_SIZE = 30;

    const auto newSize = font().pointSize() + step;

    if (newSize >= MIN_FONT_SIZE && newSize <= MAX_FONT_SIZE) {
        auto newFont = QFont(font());
        newFont.setPointSize(newSize);
        setFont(newFont);
    }
}

void TabItem::loadFile(const QString& filename)
{
    QFile file(filename);
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream in(&file);
    QString line;

    while (!in.atEnd()) {
        line = in.readLine();
        const QString html = addHtmlColor(line);
        appendHtml(html);
    }
}

QString TabItem::addHtmlColor(const QString& text) const
{
    QString color = "Black";

    if (text.contains("ERROR")) {
        color = "Red";

    } else if (text.contains("WARN")) {
        color = "Orange";

    } else if (text.contains("INFO")) {
        color = "Blue";

    } else if (text.contains("DEBUG")) {
        color = "Green";

    }

    return "<font color=\"" + color + "\">" + text + "</font>";
}
