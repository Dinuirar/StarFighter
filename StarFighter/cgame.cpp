#include "cgame.h"
#include <random>
#include <ctime>
#include <QTimer>

const int HOWMANYASTEROIDS = 3;
const qreal SHIPSCALE = 0.25;

int signed_rand() {
    return (rand() - RAND_MAX/2);
}

CGame::CGame() {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setWindowTitle( QT_TRANSLATE_NOOP(QGraphicsView, "StarFighter - The Game") );
//    menu = new CMenu(settings);
//    this->setScene(menu);
//    delete CMenu;
    menu = NULL;
    space = new CSpace(); // (settings);
    srand(std::time(0));

    // add player's ship
    player = new CShip( PLASMA, PLAYER );
    player->position = QPointF(100, 100);
    space->FListObj.push_back(player);

    GGraphics* player_g = new GGraphics("../graphics/ship-viper2.png", player);
    player_g->setScale( SHIPSCALE );
    space->addItem(player_g);
    space->FListGraphics.push_back(player_g);

    // add enemy's ship
    enemy = new CShip( LASER );
    enemy->position = QPointF(200, 200);
    space->FListObj.push_back(enemy);

    GGraphics* enemy_g = new GGraphics("../graphics/ship-viper7.png", enemy);
    enemy_g->setScale( SHIPSCALE );
    space->addItem( enemy_g );
    space->FListGraphics.push_back( enemy_g );

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
        space->FListObj.push_back(tmp);

        GGraphics * tmp_g = new GGraphics( "../graphics/basic-asteroid.png", tmp );
        tmp_g->setScale( randomscale );
        space->addItem( tmp_g );
        space->FListGraphics.push_back(tmp_g);
    }

    // animate scene
    QTimer* timer = new QTimer();
    QObject::connect(timer, &QTimer::timeout, space, &QGraphicsScene::advance);
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

        }
    }
}
