#include "casteroid.h"

CAsteroid::CAsteroid() {
}

CAsteroid::CAsteroid( int ID,
          qreal X, qreal Y, qreal ANGLE,
          qreal LINEAR_SPEEDX, qreal LINEAR_SPEEDY, qreal ANGULAR_SPEED,
          int HP )
    : id(ID),
      CObject(X, Y, ANGLE, LINEAR_SPEEDX, LINEAR_SPEEDY, ANGULAR_SPEED) {
}

CAsteroid::CAsteroid( qreal SIZE, CSpace * SPACE,
          qreal X, qreal Y, qreal ANGLE,
          qreal LINEAR_SPEEDX, qreal LINEAR_SPEEDY, qreal ANGULAR_SPEED,
          int HP )
    : CObject(X, Y, ANGLE, LINEAR_SPEEDX, LINEAR_SPEEDY, ANGULAR_SPEED) {
    this->setSpace( SPACE );
    this->setSize( SIZE );
    this->setHP(HP);
}

void CAsteroid::setModel(QString arg) {

}

bool CAsteroid::takeAHit(int dmg) {
    return true;
}

void CAsteroid::update() {

}

void CAsteroid::move() {

}

void CAsteroid::collide(CObject *) {
    // do nothing with bullet
    // do nothing with ship
    // bounce from the other asteroid
}
