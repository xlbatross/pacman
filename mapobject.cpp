#include "mapobject.h"


MapObject::MapObject(qreal xStart, qreal yStart, qreal xPos, qreal yPos, qreal width, qreal height, QGraphicsItem *parent)
    : QGraphicsRectItem(xStart + xPos * width + 0.5, yStart + yPos * height + 0.5, width - 1, height - 1, parent)
{

}

MapObject::~MapObject()
{

}

void MapObject::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = this->boundingRect();
    QBrush brush(Qt::red);

    painter->fillRect(rect, brush);
//    painter->drawRect(rect);
}
