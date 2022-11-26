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
    Pacman * pacman = new Pacman();
    Cookie * cookie = new Cookie(200,300);

    this->map->addItem(pacman);
    this->map->addItem(cookie);

    connect(this, SIGNAL(changeDirectionSignal(int)), pacman,SLOT(changeDirectionHandler(int)));
    connect(cookie, SIGNAL(eatSignal(Cookie*)), this->map, SLOT(eatCookieHandler(Cookie*)));
    connect(cookie, SIGNAL(eatSignal(Cookie*)), this, SLOT(scoreUpHandler()));
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

void MainWidget::scoreUpHandler()
{
    int score = ui->labelScore->text().toInt() + 10;
    ui->labelScore->setText(QString::number(score));
}
