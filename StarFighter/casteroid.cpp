#include "casteroid.h"

CAsteroid::CAsteroid() {

}

CAsteroid::CAsteroid( int ID,
          qreal X, qreal Y, qreal ANGLE,
          qreal LINEAR_SPEEDX, qreal LINEAR_SPEEDY, qreal ANGULAR_SPEED,
          int HP )
    : id(ID), hp(HP),
      CObject(X, Y, ANGLE, LINEAR_SPEEDX, LINEAR_SPEEDY, ANGULAR_SPEED) {

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
