#ifndef PACMAN_H
#define PACMAN_H

#include <QGraphicsObject>
#include <QPainter>
#include <QDebug>
#include <QGraphicsScene>

class Pacman : public QGraphicsObject
{
    Q_OBJECT

public:
    enum Dir{Stop = -1, Up, Down, Left, Right};

    Pacman();
    ~Pacman();

    QRectF boundingRect() const override;
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option,
               QWidget * widget) override;

protected:
    void advance(int step) override;

private:
    qreal xpos;
    qreal ypos;
    qreal width;
    qreal height;
    int dir;
    int dis;

private slots:
    void changeDirectionHandler(int dir);
};

#endif // PACMAN_H
