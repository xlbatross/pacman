#include "pacman.h"

Pacman::Pacman()
{
    this->xpos = 0;
    this->ypos = 0;
    this->width = 50;
    this->height = 50;
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

double Pacman::getWidth()
{
    return this->width;
}

double Pacman::getHeight()
{
    return this->height;
}

double Pacman::getXpos() const
{
    return this->xpos;
}

void Pacman::setXpos(double newXpos)
{
    this->xpos = newXpos;
}

double Pacman::getYpos() const
{
    return this->ypos;
}

void Pacman::setYpos(double newYpos)
{
    this->ypos = newYpos;
}

// slots
void Pacman::moveHandler(const double moveX, double moveY)
{
    this->xpos = moveX;
    this->ypos = moveY;
    this->setPos(this->xpos, this->ypos);
}

void Pacman::collisionHandler()
{
    qDebug() << "collision" << Qt::endl;
}
