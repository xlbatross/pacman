#include "gamemap.h"
#include "mapobject.h"
#include "pacman.h"

GameMap::GameMap(QGraphicsView * parent)
    : QGraphicsScene((QObject *) parent)
    , blockWidth(30)
    , blockHeight(30)
{
    parent->setScene(this);
    this->setSceneRect(QRectF(parent->pos().x(), parent->pos().y(), parent->width() - 2, parent->height() - 2));
    this->setBackgroundBrush(QBrush(Qt::white));

    // 좌표 맵 생성
    this->initPointMap(parent->width() / (int) blockWidth, parent->height() / (int) blockHeight);

    // 좌표 맵 데이터 넣기
    this->setPointMap();

    // 좌표에 따라 GUI 맵 생성
    this->setMap();
    qDebug() << this->pointMap;
}

GameMap::~GameMap()
{

}

void GameMap::initPointMap(int widthCount, int heightCount)
{
    // 좌표 맵 생성
    this->pointMap.resize(heightCount);
    for (int i = 0; i < heightCount; i++)
    {
        this->pointMap[i].resize(widthCount);
    }
}

void GameMap::setPointMap()
{
    // 좌표 맵 데이터 넣기
    int x;

    // 1번째 줄
    for (x = 0; x < this->pointMap[0].size(); x++)
        this->pointMap[0][x] = CookieType;

    // 2번째 줄
    this->pointMap[1][0] = CookieType;
    for (x = 1; x < 7; x++)
        this->pointMap[1][x] = MapObjectType;
    this->pointMap[1][7] = CookieType;
    for (x = 8; x < 19; x++)
        this->pointMap[1][x] = MapObjectType;
    this->pointMap[1][19] = CookieType;
    for (x = 20; x < 26; x++)
        this->pointMap[1][x] = MapObjectType;
    this->pointMap[1][26] = CookieType;

    // 3번째 줄
    for (x = 0; x < 6; x++)
        this->pointMap[2][x] = CookieType;
    this->pointMap[2][6] = MapObjectType;
    for (x = 7; x < 20; x++)
        this->pointMap[2][x] = CookieType;
    this->pointMap[2][20] = MapObjectType;
    for (x = 21; x < 27; x++)
        this->pointMap[2][x] = CookieType;

    // 4번째 줄
    this->pointMap[3][0] = CookieType;
    for (x = 1; x < 5; x++)
        this->pointMap[3][x] = MapObjectType;
    this->pointMap[3][5] = CookieType;
    this->pointMap[3][6] = MapObjectType;
    this->pointMap[3][7] = CookieType;
    for (x = 8; x < 13; x++)
        this->pointMap[3][x] = MapObjectType;
    this->pointMap[3][13] = CookieType;
    for (x = 14; x < 19; x++)
        this->pointMap[3][x] = MapObjectType;
    this->pointMap[3][19] = CookieType;
    this->pointMap[3][20] = MapObjectType;
    this->pointMap[3][21] = CookieType;
    for (x = 22; x < 26; x++)
        this->pointMap[3][x] = MapObjectType;
    this->pointMap[3][26] = CookieType;

    // 5번째 줄
    for (x = 0; x < 4; x++)
        this->pointMap[4][x] = CookieType;
    this->pointMap[4][4] = MapObjectType;
    this->pointMap[4][5] = CookieType;
    this->pointMap[4][6] = MapObjectType;
    for (x = 7; x < 20; x++)
        this->pointMap[4][x] = CookieType;
    this->pointMap[4][20] = MapObjectType;
    this->pointMap[4][21] = CookieType;
    this->pointMap[4][22] = MapObjectType;
    for (x = 23; x < 27; x++)
        this->pointMap[4][x] = CookieType;

    //6번째 줄
    this->pointMap[5][0] = CookieType;
    for (x = 1; x < 3; x++)
        this->pointMap[5][x] = MapObjectType;
    this->pointMap[5][3] = CookieType;
    this->pointMap[5][4] = MapObjectType;
    this->pointMap[5][5] = CookieType;
    this->pointMap[5][6] = MapObjectType;
    this->pointMap[5][7] = CookieType;
    for (x = 8; x < 13; x++)
        this->pointMap[5][x] = MapObjectType;
    this->pointMap[5][13] = CookieType;
    for (x = 14; x < 19; x++)
        this->pointMap[5][x] = MapObjectType;
    this->pointMap[5][19] = CookieType;
    this->pointMap[5][20] = MapObjectType;
    this->pointMap[5][21] = CookieType;
    this->pointMap[5][22] = MapObjectType;
    this->pointMap[5][23] = CookieType;
    for (x = 24; x < 26; x++)
        this->pointMap[5][x] = MapObjectType;
    this->pointMap[5][26] = CookieType;

    // 7번째 줄
    for (x = 0; x < 4; x++)
        this->pointMap[6][x] = CookieType;
    this->pointMap[6][4] = MapObjectType;
    for (x = 5; x < 22; x++)
        this->pointMap[6][x] = CookieType;
    this->pointMap[6][22] = MapObjectType;
    for (x = 23; x < 27; x++)
        this->pointMap[6][x] = CookieType;

    // 8번째 줄
    this->pointMap[7][0] = CookieType;
    for (x = 1; x < 3; x++)
        this->pointMap[7][x] = MapObjectType;
    this->pointMap[7][3] = CookieType;
    this->pointMap[7][4] = MapObjectType;
    this->pointMap[7][5] = CookieType;
    this->pointMap[7][6] = MapObjectType;
    this->pointMap[7][7] = CookieType;
    this->pointMap[7][8] = MapObjectType;
    this->pointMap[7][9] = CookieType;
    for (x = 10; x < 13; x++)
        this->pointMap[7][x] = MapObjectType;
    // 라인
    for (x = 14; x < 17; x++)
        this->pointMap[7][x] = MapObjectType;
    this->pointMap[7][17] = CookieType;
    this->pointMap[7][18] = MapObjectType;
    this->pointMap[7][19] = CookieType;
    this->pointMap[7][20] = MapObjectType;
    this->pointMap[7][21] = CookieType;
    this->pointMap[7][22] = MapObjectType;
    this->pointMap[7][23] = CookieType;
    for (x = 24; x < 26; x++)
        this->pointMap[7][x] = MapObjectType;
    this->pointMap[7][26] = CookieType;

    // 9번째 줄
    for (x = 0; x < 6; x++)
        this->pointMap[8][x] = CookieType;
    this->pointMap[8][6] = MapObjectType;
    this->pointMap[8][7] = CookieType;
    this->pointMap[8][8] = MapObjectType;
    this->pointMap[8][9] = CookieType;
    this->pointMap[8][10] = MapObjectType;
    this->pointMap[8][16] = MapObjectType;
    this->pointMap[8][17] = CookieType;
    this->pointMap[8][18] = MapObjectType;
    this->pointMap[8][19] = CookieType;
    this->pointMap[8][20] = MapObjectType;
    this->pointMap[8][21] = CookieType;
    this->pointMap[8][22] = MapObjectType;
    this->pointMap[8][23] = CookieType;
    for (x = 24; x < 26; x++)
        this->pointMap[8][x] = MapObjectType;
    this->pointMap[8][26] = CookieType;

    // 10번째 줄
    this->pointMap[9][0] = CookieType;
    for (x = 1; x < 3; x++)
        this->pointMap[9][x] = MapObjectType;
    this->pointMap[9][3] = CookieType;
    this->pointMap[9][4] = MapObjectType;
    this->pointMap[9][5] = CookieType;
    this->pointMap[9][6] = MapObjectType;
    this->pointMap[9][7] = CookieType;
    this->pointMap[9][8] = MapObjectType;
    this->pointMap[9][9] = CookieType;
    this->pointMap[9][10] = MapObjectType;
    this->pointMap[9][16] = MapObjectType;
    this->pointMap[9][17] = CookieType;
    this->pointMap[9][18] = MapObjectType;
    this->pointMap[9][19] = CookieType;
    this->pointMap[9][20] = MapObjectType;
    for (x = 21; x < 27; x++)
        this->pointMap[9][x] = CookieType;

    // 11번째 줄
    this->pointMap[10][0] = CookieType;
    for (x = 1; x < 3; x++)
        this->pointMap[10][x] = MapObjectType;
    this->pointMap[10][3] = CookieType;
    this->pointMap[10][4] = MapObjectType;
    this->pointMap[10][5] = CookieType;
    this->pointMap[10][6] = MapObjectType;
    this->pointMap[10][7] = CookieType;
    this->pointMap[10][8] = MapObjectType;
    this->pointMap[10][9] = CookieType;
    for (x = 10; x < 17; x++)
        this->pointMap[10][x] = MapObjectType;
    this->pointMap[10][17] = CookieType;
    this->pointMap[10][18] = MapObjectType;
    this->pointMap[10][19] = CookieType;
    this->pointMap[10][20] = MapObjectType;
    this->pointMap[10][21] = CookieType;
    this->pointMap[10][22] = MapObjectType;
    this->pointMap[10][23] = CookieType;
    for (x = 24; x < 26; x++)
        this->pointMap[10][x] = MapObjectType;
    this->pointMap[10][26] = CookieType;

    // 12번째 줄
    for (x = 0; x < 4; x++)
        this->pointMap[11][x] = CookieType;
    this->pointMap[11][4] = MapObjectType;
    for (x = 5; x < 22; x++)
        this->pointMap[11][x] = CookieType;
    this->pointMap[11][22] = MapObjectType;
    for (x = 23; x < 27; x++)
        this->pointMap[11][x] = CookieType;

    // 13번째 줄
    this->pointMap[12][0] = CookieType;
    for (x = 1; x < 3; x++)
        this->pointMap[12][x] = MapObjectType;
    this->pointMap[12][3] = CookieType;
    this->pointMap[12][4] = MapObjectType;
    this->pointMap[12][5] = CookieType;
    this->pointMap[12][6] = MapObjectType;
    this->pointMap[12][7] = CookieType;
    for (x = 8; x < 13; x++)
        this->pointMap[12][x] = MapObjectType;
    this->pointMap[12][13] = CookieType;
    for (x = 14; x < 19; x++)
        this->pointMap[12][x] = MapObjectType;
    this->pointMap[12][19] = CookieType;
    this->pointMap[12][20] = MapObjectType;
    this->pointMap[12][21] = CookieType;
    this->pointMap[12][22] = MapObjectType;
    this->pointMap[12][23] = CookieType;
    for (x = 24; x < 26; x++)
        this->pointMap[12][x] = MapObjectType;
    this->pointMap[12][26] = CookieType;

    // 14번쨰 줄
    for (x = 0; x < 4; x++)
         this->pointMap[13][x] = CookieType;
    this->pointMap[13][4] = MapObjectType;
    this->pointMap[13][5] = CookieType;
    this->pointMap[13][6] = MapObjectType;
    for (x = 7; x < 13; x++)
        this->pointMap[13][x] = CookieType;
    this->pointMap[13][13] = PacmanType;
    for (x = 14; x < 20; x++)
        this->pointMap[13][x] = CookieType;
    this->pointMap[13][20] = MapObjectType;
    this->pointMap[13][21] = CookieType;
    this->pointMap[13][22] = MapObjectType;
    for (x = 23; x < 27; x++)
        this->pointMap[13][x] = CookieType;

    // 15번째 줄 4번째 줄과 동일
    this->pointMap[14][0] = CookieType;
    for (x = 1; x < 5; x++)
        this->pointMap[14][x] = MapObjectType;
    this->pointMap[14][5] = CookieType;
    this->pointMap[14][6] = MapObjectType;
    this->pointMap[14][7] = CookieType;
    for (x = 8; x < 13; x++)
        this->pointMap[14][x] = MapObjectType;
    this->pointMap[14][13] = CookieType;
    for (x = 14; x < 19; x++)
        this->pointMap[14][x] = MapObjectType;
    this->pointMap[14][19] = CookieType;
    this->pointMap[14][20] = MapObjectType;
    this->pointMap[14][21] = CookieType;
    for (x = 22; x < 26; x++)
        this->pointMap[14][x] = MapObjectType;
    this->pointMap[14][26] = CookieType;

    // 16번째 줄 3번째 줄과 동일
    for (x = 0; x < 6; x++)
        this->pointMap[15][x] = CookieType;
    this->pointMap[15][6] = MapObjectType;
    for (x = 7; x < 20; x++)
        this->pointMap[15][x] = CookieType;
    this->pointMap[15][20] = MapObjectType;
    for (x = 21; x < 27; x++)
        this->pointMap[15][x] = CookieType;

    // 17번째 줄 2번째 줄과 동일
    this->pointMap[16][0] = CookieType;
    for (x = 1; x < 7; x++)
        this->pointMap[16][x] = MapObjectType;
    this->pointMap[16][7] = CookieType;
    for (x = 8; x < 19; x++)
        this->pointMap[16][x] = MapObjectType;
    this->pointMap[16][19] = CookieType;
    for (x = 20; x < 26; x++)
        this->pointMap[16][x] = MapObjectType;
    this->pointMap[16][26] = CookieType;

    // 18번째 줄 1번째 줄과 동일
    for (x = 0; x < this->pointMap[17].size(); x++)
        this->pointMap[17][x] = CookieType;


}

void GameMap::setMap()
{
    QRectF scene = this->sceneRect();
    for (int y = 0; y < this->pointMap.size(); y++)
    {
        for (int x = 0; x < this->pointMap[y].size(); x++)
        {
            switch(this->pointMap[y][x])
            {
            case CookieType:
            {
                Cookie * cookie = new Cookie(scene.x(), scene.y(), x, y, this->blockWidth, this->blockHeight);
                this->addItem(cookie);
                connect(cookie, SIGNAL(eatSignal(Cookie*)), this, SLOT(eatCookieHandler(Cookie*)));
            } break;
            case MapObjectType:
            {
                MapObject * wall = new MapObject(scene.x(), scene.y(), x, y, this->blockWidth, this->blockHeight);
                this->addItem(wall);
            } break;
            case PacmanType:
            {
                Pacman * pacman = new Pacman(scene.x(), scene.y(), x, y, this->blockWidth, this->blockHeight, this->pointMap);
                this->addItem(pacman);
                connect(this, SIGNAL(changeDirectionSignal(int)), pacman, SLOT(changeDirectionHandler(int)));
            } break;
            }
        }
    }
}

// slot
void GameMap::changeDirectionHandler(int dir)
{
    emit changeDirectionSignal(dir);
}

void GameMap::eatCookieHandler(Cookie * cookie)
{
    this->removeItem(cookie);
    emit eatSignal(10);
}




