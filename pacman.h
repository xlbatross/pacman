#ifndef PACMAN_H
#define PACMAN_H

#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsObject>
#include <QDebug>

class Pacman : public QGraphicsObject
{
    Q_OBJECT

public:
    Pacman();
    QRectF boundingRect() const;
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);

    double getWidth();
    double getHeight();

    double getXpos() const;
    void setXpos(double newXpos);

    double getYpos() const;
    void setYpos(double newYpos);

private:
    double xpos;
    double ypos;
    double width;
    double height;

public slots:
    void moveHandler(const double moveX, const double moveY);
    void collisionHandler();
};

#endif // PACMAN_H
