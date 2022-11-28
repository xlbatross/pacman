#include "cookie.h"
#include "pacman.h"

Cookie::Cookie(qreal xStart, qreal yStart, qreal xPoint, qreal yPoint, qreal blockWidth, qreal blockHeight)
{
    QRectF block(xStart + xPoint * blockWidth, yStart + yPoint * blockHeight, blockWidth, blockHeight);
    this->bSize = 5;
    this->xPos = block.center().x() - this->bSize / 2;
    this->yPos = block.center().y() - this->bSize / 2;
}

Cookie::~Cookie()
{

}

QRectF Cookie::boundingRect() const
{
    return QRectF(xPos, yPos, bSize, bSize);
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
            break;
        }
    }
}
