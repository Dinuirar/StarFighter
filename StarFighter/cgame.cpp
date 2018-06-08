#include "cgame.h"
#include "common.h"
#include <random>
#include <ctime>
#include <QTimer>

int signed_rand() {
    return (rand() - RAND_MAX/2);
}

CGame::CGame() {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setWindowTitle( QT_TRANSLATE_NOOP(QGraphicsView, "StarFighter - The Game") );
    setSceneRect( QRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT) );
    setAlignment( Qt::AlignTop );
    //    menu = new CMenu(settings);
    //    this->setScene(menu);
    //    delete CMenu;
    menu = NULL;
    space = new CSpace(); // (settings);
    srand(std::time(0));

    // add player's ship
    player = new CShip( 10, LASER, PLAYER, space, QPoint(300, 400) );
    GGraphics* player_g = new GGraphics("../graphics/ship-viper2.png", player, SHIPSCALE);
    space->addObject( player, player_g);

    // add enemy's ship
    enemy = new CShip( 10, PLASMA, NPC, space, QPoint(400, 300) );
    GGraphics* enemy_g = new GGraphics("../graphics/ship-raider.png", enemy, SHIPSCALE);
    space->addObject(enemy, enemy_g);

    // add some asteroids to FListObj
    double randomspeedlinearX, randomspeedlinearY, randomspeedangular;
    qreal randomscale;
    for ( u_int i = 0; i < HOWMANYASTEROIDS; i++ ) {
        randomscale = 0.6 * (double( rand() ) / 2 / RAND_MAX) + 0.2;
        randomspeedlinearX = signed_rand() %11;
        randomspeedlinearY = signed_rand()%11;
        randomspeedangular = signed_rand()%5;
        CAsteroid * tmp = new CAsteroid( randomscale * 100, space,
                    rand()%WINDOW_WIDTH, rand()%WINDOW_HEIGHT, signed_rand()%360,
                    randomspeedlinearX, randomspeedlinearY, randomspeedangular, 50);
        GGraphics * tmp_g = new GGraphics( "../graphics/" + asteroids[ rand()%4 ], tmp );
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

void CGame::keyPressEvent(QKeyEvent * event) {
    if( menu ) return; // mode -> menu
    else { // mode -> space
//        CShip* ship;
//        for (size_t i = 0; i < space->FListObj.size(); i++) { // find player's ship
//            ship = dynamic_cast<CShip*>( space->FListObj[i] ); // try to cast object to ship
//            if ( !ship ) continue; // if object is not a ship - continue to the next element
//            if (ship->getID() != PLAYER) continue; // if ship is not a PLAYER - continue to the next element
//            else {
//                break; // if object is of class CShip and id is PLAYER, than the player's ship has been found
//            }
//        }
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
        else if ( event->key() == Qt::Key_0  ) {
            player->attack();
        }

        if( event->key() == Qt::Key_W) {
            enemy->accelerateLinear();
        }
        else if( event->key() == Qt::Key_S) {
            enemy->accelerateLinear(true);
        }
        else if ( event->key() == Qt::Key_A ) {
            enemy->accelerateAngular(false);
        }
        else if ( event->key() == Qt::Key_D ) {
            enemy->accelerateAngular(true);
        }
        else if ( event->key() == Qt::Key_Space ) {
            enemy->attack();
        }


        else if (event->key() == Qt::Key_Escape) {
            delete this;
        }
    }
}
