#ifndef PACMANTHREAD_H
#define PACMANTHREAD_H

#include <QThread>
#include "pacman.h"

class PacmanThread : public QThread
{
    Q_OBJECT
public:
    enum Dir{Up, Down, Left, Right, Stop};
    PacmanThread(QGraphicsScene * map, Pacman * pm);

private:
    QGraphicsScene * map;
    Pacman * pacman;
    int dir;
    double dis;
    void run() override;

    void moveDirection();
    void collisionCheck();

private slots:
    void changeDirection(const int & dir);

signals:
    void moveSignal(const double moveX, const double moveY);
    void collisionSignal();
};

#endif // PACMANTHREAD_H
