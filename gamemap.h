#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include "cookie.h"

class GameMap : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit GameMap(QGraphicsView * parent);
    ~GameMap();

public slots:
    void eatCookieHandler(Cookie *);

};

#endif // GAMEMAP_H
