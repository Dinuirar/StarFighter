#include "cgame.h"
#include "common.h"
#include <random>
#include <ctime>
#include <QTimer>

void CGame::initMenu() {
        menu = nullptr;
}

void CGame::initGame() {
    space = new CSpace();

    // add player's ship
    player = new CShip( 35, LASER, PLAYER, space, QPoint(300, 400) );
    GGraphics* player_g = new GGraphics(ship_graphics, player, SHIPSCALE);
    space->addObject( player, player_g);

    // add some asteroids to FListObj
    double randomspeedlinearX, randomspeedlinearY, randomspeedangular;
    qreal randomscale;
    for ( u_int i = 0; i < HOWMANYASTEROIDS; i++ ) {
        randomscale = 0.5;
        randomspeedlinearX = 0;
        randomspeedlinearY = 0;
        randomspeedangular = 0;
        CAsteroid * tmp = new CAsteroid( randomscale * 100, space,
                    i * 100 + 50, 2 * 100, 0,
                    randomspeedlinearX, randomspeedlinearY, randomspeedangular, 50);
        GGraphics * tmp_g = new GGraphics( graphics_dir + asteroids[ 0 ], tmp );
        tmp_g->setScale( randomscale );
        space->addObject( tmp, tmp_g );
    }

    // update objects
    QTimer* timer2 = new QTimer();
    QObject::connect(timer2,
                     &QTimer::timeout,
                     space,
                     &CSpace::updateObjs);
    timer2->start(1000 / 33);

    // draw animated scene
    QTimer* timer = new QTimer();
    QObject::connect(timer, // sender
                     &QTimer::timeout, // signal
                     space, // receiver
                     &QGraphicsScene::advance); // member
    timer->start(1000 / 33);

    this->setScene(space);
}

CGame::CGame() {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setWindowTitle( QT_TRANSLATE_NOOP(QGraphicsView, "StarFighter - The Game") );
    setSceneRect( QRect(0, 0,
                        static_cast<int>(WINDOW_WIDTH),
                        static_cast<int>(WINDOW_HEIGHT))
                  );
    setAlignment( Qt::AlignTop );

    this->initMenu();
    this->initGame();
}

void CGame::keyPressEvent(QKeyEvent * event) {
    if( menu ) { return; } // mode -> menu
    else { // mode -> space
        if( event->key() == Qt::Key_Up) {
            player->accelerateLinear();
        }
        else if( event->key() == Qt::Key_Down) {
            player->accelerateLinear(true);
        }
        else if ( event->key() == Qt::Key_Left ) {
            player->accelerateAngular(false);
        }
        else if ( event->key() == Qt::Key_Right ) {
            player->accelerateAngular(true);
        }
        else if ( event->key() == Qt::Key_Space  ) {
            player->attack();
        }
        else if (event->key() == Qt::Key_Escape) {
            delete this;
        }
    }
}
