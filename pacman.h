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

    Pacman(qreal xStart, qreal yStart, qreal xPoint, qreal yPoint, qreal blockWidth, qreal blockHeight,
           const QVector<QVector<qint8>> & pointMap);
    ~Pacman();

    QRectF boundingRect() const override;
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option,
               QWidget * widget) override;

protected:
    void advance(int step) override;

private:
    const QVector<QVector<qint8>> & pointMap;
    qreal xPos;
    qreal yPos;
    qreal xStart;
    qreal yStart;
    qreal xPoint;
    qreal yPoint;
    qreal width;
    qreal height;
    int nowDir;
    int nextDir;
    int dis;

    qreal xCurrentPoint() { return (this->xPos - this->xStart) / this->width; }
    qreal yCurrentPoint() { return (this->yPos - this->yStart) / this->height; }


private slots:
    void changeDirectionHandler(int dir);
};

#endif // PACMAN_H
