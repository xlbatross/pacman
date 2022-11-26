#include "pacmanthread.h"
#include <typeinfo>

PacmanThread::PacmanThread(QGraphicsScene * map, Pacman * pm)
    : map(map)
    , pacman(pm)
{
    this->dir = Up;
    this->dis = 4;

    connect(this, SIGNAL(moveSignal(double,double)), this->pacman, SLOT(moveHandler(double,double)));
    connect(this, SIGNAL(collisionSignal()), this->pacman, SLOT(collisionHandler()));
}


void PacmanThread::run()
{
    while (true)
    {
        this->collisionCheck();
        this->moveDirection();
        this->msleep(1);
    }
}

void PacmanThread::moveDirection()
{
    double moveX = this->pacman->getXpos();
    double moveY = this->pacman->getYpos();

    switch (this->dir) {
    case Up:
        moveY = (moveY >= this->dis) ? moveY - this->dis : 0;
        break;
    case Left:
        moveX = (moveX >= this->dis) ? moveX - this->dis : 0;
        break;
    case Down:
        moveY = (moveY + this->pacman->getHeight() <= this->map->height() - this->dis) ? moveY + this->dis : this->map->height() - this->pacman->getHeight();
        break;
    case Right:
        moveX = (moveX + this->pacman->getWidth() <= this->map->width() - this->dis) ? moveX + this->dis : this->map->width() - this->pacman->getWidth();
        break;
    }
    emit this->moveSignal(moveX, moveY);
}

void PacmanThread::collisionCheck()
{
    QList<QGraphicsItem *> collidingItems = this->pacman->collidingItems();

    for (int i = 0; i < collidingItems.size(); i++)
    {
        if (typeid(QGraphicsItem *) == typeid(collidingItems[i]))
        {
            QRectF otherRect = collidingItems[i]->boundingRect();
            switch(this->dir)
            {
            case Up:
                this->pacman->setYpos(otherRect.y() + otherRect.height());
                break;
            case Down:
                this->pacman->setYpos(otherRect.y() - this->pacman->getHeight());
                break;
            case Left:
                this->pacman->setXpos(otherRect.x() + otherRect.width());
                break;
            case Right:
                this->pacman->setXpos(otherRect.x() - this->pacman->getWidth());
                break;
            }
            this->dir = Stop;
        }
    }
}

// slots
void PacmanThread::changeDirection(const int & dir)
{
    this->dir = dir;
}
