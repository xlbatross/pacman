#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QGraphicsScene>
#include <QWidget>
#include <QKeyEvent>
#include "pacmanthread.h"
#include "pacman.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
    void keyPressEvent(QKeyEvent * event) override;

private:
    Ui::MainWidget *ui;
    QGraphicsScene * map;
    Pacman * pacman;
    PacmanThread * pacmanThread;

signals:
    void changeDirection(const int & dir);
};
#endif // MAINWIDGET_H
