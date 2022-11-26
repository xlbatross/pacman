#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <QGraphicsScene>
#include <QGraphicsView>

class GameMap : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit GameMap(QGraphicsView * parent);
    ~GameMap();
};

#endif // GAMEMAP_H
