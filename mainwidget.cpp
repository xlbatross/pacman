#include "mainwidget.h"
#include "./ui_mainwidget.h"
#include "pacman.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
    , timer(new QTimer(this))
{
    ui->setupUi(this);

    this->map = new GameMap(ui->graphicsView);

    connect(this, SIGNAL(changeDirectionSignal(int)), this->map, SLOT(changeDirectionHandler(int)));
    connect(this->map, SIGNAL(eatSignal(int)), this, SLOT(scoreUpHandler(int)));

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

void MainWidget::scoreUpHandler(int point)
{
    int score = ui->labelScore->text().toInt() + point;
    ui->labelScore->setText(QString::number(score));
}
