#include "pacman.h"
#include "gamemap.h"
#include <cmath>

Pacman::Pacman(qreal xStart, qreal yStart, qreal xPoint, qreal yPoint,
               qreal blockWidth, qreal blockHeight, const QVector<QVector<qint8>> & pointMap)
    : xStart(xStart)
    , yStart(yStart)
    , xPoint(xPoint)
    , yPoint(yPoint)
    , width(blockWidth)
    , height(blockHeight)
    , nowDir(Left)
    , nextDir(Stop)
    , dis(1)
    , pointMap(pointMap)

{
    this->xPos = this->xStart + this->xPoint * this->width;
    this->yPos = this->yStart + this->yPoint * this->height;
}

Pacman::~Pacman()
{

}

QRectF Pacman::boundingRect() const
{
    // QRectF의 앞의 두 개의 인자는 기준점을 의미하는 듯
    return QRectF(0, 0, this->width, this->height);
}

void Pacman::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = this->boundingRect();
    QBrush brush(Qt::black);

    painter->fillRect(rect, brush);
//    painter->drawRect(rect);
}

void Pacman::advance(int step)
{
    if (!step)
        return;

    qDebug() << "x : " << this->xCurrentPoint()
             << "y : " << this->yCurrentPoint();

    int x = xCurrentPoint();
    int y = yCurrentPoint();
    switch(this->nextDir)
    {
    case Up:
    {
        x = (this->nowDir == Left) ? floor(xCurrentPoint()) : ceil(xCurrentPoint());
        if (x == xCurrentPoint() && (y > 0 && this->pointMap[y - 1][x] != GameMap::MapObjectType))
        {
            this->nowDir = Up;
            this->nextDir = Stop;
        }
    } break;
    case Down:
    {
        x = (this->nowDir == Left) ? floor(xCurrentPoint()) : ceil(xCurrentPoint());
        if (x == xCurrentPoint() && (y < this->pointMap.size() - 1 && this->pointMap[y + 1][x] != GameMap::MapObjectType))
        {
            this->nowDir = Down;
            this->nextDir = Stop;
        }
    } break;
    case Left:
    {
        y = (this->nowDir == Up) ? floor(yCurrentPoint()) : ceil(yCurrentPoint());
        if (y == yCurrentPoint() && (x > 0 && this->pointMap[y][x - 1] != GameMap::MapObjectType))
        {
            this->nowDir = Left;
            this->nextDir = Stop;
        }
    } break;
    case Right:
    {
        y = (this->nowDir == Up) ? floor(yCurrentPoint()) : ceil(yCurrentPoint());
        if (y == yCurrentPoint() && (x < this->pointMap[y].size() - 1 && this->pointMap[y][x + 1] != GameMap::MapObjectType))
        {
            this->nowDir = Right;
            this->nextDir = Stop;
        }
    } break;
    }

    // collision check to pointmap
    x = xCurrentPoint();
    y = yCurrentPoint();
    switch(this->nowDir)
    {
    case Up:
    {
        y = ceil(yCurrentPoint());
        if (y > 0 && this->pointMap[y - 1][x] == GameMap::MapObjectType)
            this->nowDir = Stop;
    } break;
    case Down:
    {
        y = floor(yCurrentPoint());
        if (y < this->pointMap.size() - 1 && this->pointMap[y + 1][x] == GameMap::MapObjectType)
            this->nowDir = Stop;
    } break;
    case Left:
    {
        x = ceil(xCurrentPoint());
        if (x > 0 && this->pointMap[y][x - 1] == GameMap::MapObjectType)
            this->nowDir = Stop;
    } break;
    case Right:
    {
        x = floor(xCurrentPoint());
        if (x < this->pointMap[y].size() - 1 && this->pointMap[y][x + 1] == GameMap::MapObjectType)
            this->nowDir = Stop;
    } break;
    }

    // move
    QRectF sceneRect = this->scene()->sceneRect();
    switch (this->nowDir) {
    case Up:
        this->yPos = (this->yPos >= sceneRect.y() + this->dis) ? this->yPos - this->dis : sceneRect.y();
        break;
    case Left:
        this->xPos = (this->xPos >= sceneRect.x() + this->dis) ? this->xPos - this->dis : sceneRect.x();
        break;
    case Down:
        this->yPos = (this->yPos + this->height <= sceneRect.y() + this->scene()->height() - this->dis) ? this->yPos + this->dis : sceneRect.y() + this->scene()->height() - this->height;
        break;
    case Right:
        this->xPos = (this->xPos + this->width <= sceneRect.x() + this->scene()->width() - this->dis) ? this->xPos + this->dis : sceneRect.x() + this->scene()->width() - this->width;
        break;
    }

    this->setPos(this->xPos, this->yPos);
}

// slots
void Pacman::changeDirectionHandler(int dir)
{
    this->nextDir = dir;
}
