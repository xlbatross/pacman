#include "mapobject.h"

MapObject::MapObject(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent)
    : QGraphicsRectItem(x, y, width, height, parent)
{

}

MapObject::~MapObject()
{

}

QRectF MapObject::boundingRect() const
{
    return QRectF(0,0, 50, 50);
}

void MapObject::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = this->boundingRect();
    QBrush brush(Qt::black);

    painter->fillRect(rect, brush);
    painter->drawRect(rect);
}
