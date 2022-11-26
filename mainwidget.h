#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include <QTimer>
#include "pacman.h"
#include "gamemap.h"

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
    GameMap * map;
    Pacman * pacman;
    QTimer * timer;

signals:
    void changeDirectionSignal(int dir);
};
#endif // MAINWIDGET_H
