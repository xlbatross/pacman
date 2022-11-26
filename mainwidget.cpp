#include "mainwidget.h"
#include "./ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
    , timer(new QTimer(this))
{
    ui->setupUi(this);

    this->map = new GameMap(ui->graphicsView);
    this->pacman = new Pacman();

    this->map->addItem(pacman);

    connect(this, SIGNAL(changeDirectionSignal(int)), this->pacman,SLOT(changeDirectionHandler(int)));
    connect(this->timer, SIGNAL(timeout()), this->map, SLOT(advance()));
    timer->start(10);
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::keyPressEvent(QKeyEvent * event)
{
    int key = Pacman::Stop;
    switch(event->key())
    {
    case Qt::Key_W : key = Pacman::Up; break;
    case Qt::Key_A : key = Pacman::Left; break;
    case Qt::Key_S : key = Pacman::Down; break;
    case Qt::Key_D : key = Pacman::Right; break;
    }
    if (key > Pacman::Stop)
    {
        emit this->changeDirectionSignal(key);
    }
}
