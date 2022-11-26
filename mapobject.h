#ifndef MAPOBJECT_H
#define MAPOBJECT_H

#include <QGraphicsRectItem>
#include <QPainter>

class MapObject : public QGraphicsRectItem
{
public:
    MapObject(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = nullptr);
    ~MapObject();

    QRectF boundingRect() const;
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);


};

#endif // MAPOBJECT_H
