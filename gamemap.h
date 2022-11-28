#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <QVector>
#include "cookie.h"

class GameMap : public QGraphicsScene
{
    Q_OBJECT

public:
    enum Type{NoneType, MapObjectType, CookieType, PacmanType};

    explicit GameMap(QGraphicsView * parent);
    ~GameMap();

    void initPointMap(int widthCount, int heightCount);
    void setPointMap();
    void setMap();

private:
    qreal blockWidth;
    qreal blockHeight;
    QVector<QVector<qint8>> pointMap;

public slots:
    void changeDirectionHandler(int dir);
    void eatCookieHandler(Cookie *);

signals:
    void changeDirectionSignal(int dir);
    void eatSignal(int point);

};

#endif // GAMEMAP_H
