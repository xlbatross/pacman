#include "mainwidget.h"
#include "./ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
    , map(new QGraphicsScene)
    , pacman(new Pacman)
    , pacmanThread(new PacmanThread(this->map, this->pacman))
{
    ui->setupUi(this);

    ui->graphicsView->setScene(this->map);
    this->map->setSceneRect(QRectF(ui->graphicsView->pos().x(), ui->graphicsView->pos().y(), ui->graphicsView->width() - 2, ui->graphicsView->height() - 2));
    this->map->setBackgroundBrush(QBrush(Qt::blue));
    this->map->addItem(pacman);
    this->map->addRect(QRectF(100, 203, 100, 50));

    this->pacmanThread->start();

    connect(this, SIGNAL(changeDirection(int)), this->pacmanThread, SLOT(changeDirection(int)));
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::keyPressEvent(QKeyEvent * event)
{
    switch(event->key())
    {
    case Qt::Key_W : emit this->changeDirection(PacmanThread::Up); break;
    case Qt::Key_A : emit this->changeDirection(PacmanThread::Left); break;
    case Qt::Key_S : emit this->changeDirection(PacmanThread::Down); break;
    case Qt::Key_D : emit this->changeDirection(PacmanThread::Right); break;
    }
}
