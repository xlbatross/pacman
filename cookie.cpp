#include "cookie.h"
#include "pacman.h"

Cookie::Cookie(qreal xPos, qreal yPos)
    : xPos(xPos)
    , yPos(yPos)
{

}

Cookie::~Cookie()
{

}

QRectF Cookie::boundingRect() const
{
    return QRectF(xPos, yPos, 50, 50);
}

void Cookie::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = this->boundingRect();
    QBrush brush(Qt::yellow);

    painter->setBrush(brush);
    painter->drawEllipse(rect);

}

void Cookie::advance(int step)
{
    if (!step)
        return;

    QList<QGraphicsItem *> collidingItems = this->collidingItems();

    for (int i = 0; i < collidingItems.size(); i++)
    {
        if (dynamic_cast<Pacman *>(collidingItems[i]))
        {
            emit eatSignal(this);
        }
    }
}
