#include "cgame.h"
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
    player = new CShip( LASER, PLAYER );
    player->setSpace( space );
    player->setPosition( QPointF(100, 100) );

    GGraphics* player_g = new GGraphics("../graphics/ship-viper2.png", player);
    player_g->setScale( SHIPSCALE );

    space->addObject( player, player_g);

    // add enemy's ship
    enemy = new CShip( KINETIC, NPC );
    enemy->setSpace( space );
    enemy->setPosition ( QPointF(200, 200) );

    GGraphics* enemy_g = new GGraphics("../graphics/ship-viper7.png", enemy);
    enemy_g->setScale( SHIPSCALE );

    space->addObject(enemy, enemy_g);

    // add some asteroids to FListObj
    double randomscale;
    double randomspeedlinearX, randomspeedlinearY;
    double randomspeedangular;
    double randomX, randomY, randomAngle;
    for ( int i = 0; i < HOWMANYASTEROIDS; i++ ) {
        randomscale = 0.6 * (double( rand() ) / 2 / RAND_MAX) + 0.2; // scale from 0.2 to 0.8
        randomspeedlinearX = signed_rand() %11;
        randomspeedlinearY = signed_rand()%11;
        randomspeedangular = signed_rand()%5;
        randomX = rand()%WINDOW_WIDTH;
        randomY = rand()%WINDOW_HEIGHT;
        randomAngle = signed_rand()%360;
        CAsteroid * tmp = new CAsteroid(
                    randomX, randomY, randomAngle,
                    randomspeedlinearX, randomspeedlinearY, randomspeedangular, 10);
        GGraphics * tmp_g = new GGraphics( "../graphics/basic-asteroid.png", tmp );
        tmp_g->setScale( randomscale );
        space->addObject(tmp, tmp_g);
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
        CShip* ship;
        ship = player;
//        for (size_t i = 0; i < space->FListObj.size(); i++) { // find player's ship
//            ship = dynamic_cast<CShip*>( space->FListObj[i] ); // try to cast object to ship
//            if ( !ship ) continue; // if object is not a ship - continue to the next element
//            if (ship->getID() != PLAYER) continue; // if ship is not a PLAYER - continue to the next element
//            else {
//                break; // if object is of class CShip and id is PLAYER, than the player's ship has been found
//            }
//        }
        if( event->key() == Qt::Key_Up) {
            ship->accelerateLinear();
        }
        else if( event->key() == Qt::Key_Down) {
            ship->accelerateLinear(true);
        }
        else if ( event->key() == Qt::Key_Left ) {
            ship->accelerateAngular(false);
        }
        else if ( event->key() == Qt::Key_Right ) {
            ship->accelerateAngular(true);
        }
        else if ( event->key() == Qt::Key_Shift ) {
            ship->attack();
        }
        else if (event->key() == Qt::Key_Escape) {
            delete this;
        }
    }
}
