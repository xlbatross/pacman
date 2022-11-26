#include "mapobject.h"


MapObject::MapObject(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent)
    : QGraphicsRectItem(x, y, width, height, parent)
{

}

MapObject::~MapObject()
{

}

void MapObject::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    qDebug() << this->boundingRect();
    QRectF rect = this->boundingRect();
    QBrush brush(Qt::red);

    painter->fillRect(rect, brush);
    painter->drawRect(rect);
}
