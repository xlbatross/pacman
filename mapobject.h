#ifndef MAPOBJECT_H
#define MAPOBJECT_H

#include <QGraphicsRectItem>
#include <QPainter>
#include <QDebug>

class MapObject : public QGraphicsRectItem
{
public:
    MapObject(qreal xStart, qreal yStart,
              qreal xPos, qreal yPos,
              qreal width, qreal height,
              QGraphicsItem *parent = nullptr);
    ~MapObject();

    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option,
               QWidget * widget);

};

#endif // MAPOBJECT_H
