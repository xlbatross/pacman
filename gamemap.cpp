#include "gamemap.h"
#include "mapobject.h"

GameMap::GameMap(QGraphicsView * parent)
    : QGraphicsScene((QObject *) parent)
{
    parent->setScene(this);
    this->setSceneRect(QRectF(parent->pos().x(), parent->pos().y(), parent->width() - 2, parent->height() - 2));
    this->setBackgroundBrush(QBrush(Qt::white));
    this->addItem(new MapObject(0, 0, 50, 50));
    this->addItem(new MapObject(100, 200, 100, 50));
    this->addItem(new MapObject(100, 250, 50, 50));
}

GameMap::~GameMap()
{

}

// slot
void GameMap::eatCookieHandler(Cookie * cookie)
{
    this->removeItem(cookie);
}
