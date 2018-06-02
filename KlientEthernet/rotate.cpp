#include "rotate.h"
#include <QPainter>


rotate::rotate(QWidget *parent)
    : QLabel(parent)
{

}

rotate::rotate(const QString &text, QWidget *parent)
: QLabel(text, parent)
{
}

void rotate::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.setBrush(Qt::Dense1Pattern);

    painter.rotate(90);

    painter.drawText(0,0, text());
}

QSize rotate::minimumSizeHint() const
{
    QSize s = QLabel::minimumSizeHint();
    return QSize(s.height(), s.width());
}

QSize rotate::sizeHint() const
{
    QSize s = QLabel::sizeHint();
    return QSize(s.height(), s.width());
}
