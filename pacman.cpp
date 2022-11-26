#include "pacman.h"
#include "mapobject.h"

Pacman::Pacman()
{
    this->xpos = 0;
    this->ypos = 0;
    this->width = 50;
    this->height = 50;
    this->dir = Up;
    this->dis = 4;
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
    painter->drawRect(rect);
}

void Pacman::advance(int step)
{
    if (!step)
        return;

    // collision check
    const QList<QGraphicsItem *> collidingItems = this->collidingItems();

    for (int i = 0; i < collidingItems.size(); i++)
    {
        if (dynamic_cast<MapObject *>(collidingItems[i]))
        {
            QRectF otherRect = collidingItems[i]->boundingRect();

            switch(this->dir)
            {
            case Up:
                if (otherRect.y() <= this->ypos)
                    this->ypos = otherRect.y() + otherRect.height();
                qDebug() << "stop from up";
                break;
            case Down:
                if (otherRect.y() >= this->ypos)
                    this->ypos = otherRect.y() - this->height;
                qDebug() << "stop from down";
                break;
            case Left:
                if (otherRect.x() <= this->xpos)
                    this->xpos = otherRect.x() + otherRect.width();
                qDebug() << "stop from left";
                break;
            case Right:
                if (otherRect.x() >= this->xpos)
                    this->xpos = otherRect.x() - this->width;
                qDebug() << "stop from right";
                break;
            }
            this->dir = Stop;
        }
    }

    // move

    switch (this->dir) {
    case Up:
        this->ypos = (this->ypos >= this->dis) ? this->ypos - this->dis : 0;
        break;
    case Left:
        this->xpos = (this->xpos >= this->dis) ? this->xpos - this->dis : 0;
        break;
    case Down:
        this->ypos = (this->ypos + this->height <= this->scene()->height() - this->dis) ? this->ypos + this->dis : this->scene()->height() - this->height;
        break;
    case Right:
        this->xpos = (this->xpos + this->width <= this->scene()->width() - this->dis) ? this->xpos + this->dis : this->scene()->width() - this->width;
        break;
    }

    this->setPos(this->xpos, this->ypos);
}

// slots
void Pacman::changeDirectionHandler(int dir)
{
    this->dir = dir;
}
