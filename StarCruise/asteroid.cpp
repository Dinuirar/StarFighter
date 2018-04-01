#include "asteroid.h"

///////////////////////////////////////////////////////////
CAsteroid::CAsteroid() {
}

CAsteroid::CAsteroid(QString MODEL, int ID,
         qreal X, qreal Y, qreal ANGLE,
         qreal LINEAR_SPEED, qreal ANGULAR_SPEED, int HP)
    : CInertion(X, Y, ANGLE, LINEAR_SPEED, ANGULAR_SPEED),
      id(ID), modelName(MODEL), hp(HP) {
    setPixmap( QPixmap::fromImage( QImage (modelName) ));
}

void CAsteroid::setModel(QString arg) {
    modelName = arg;
}

bool CAsteroid::takeAHit(int dmg) {
    hp -= dmg;
    if (hp < 0) return false;
    return true;
}

/////////////////////////////////////////////////////////////
//SmallAsteroid::SmallAsteroid() {
//    hp = defaultHP;
//}

/////////////////////////////////////////////////////////////
//MediumAsteroid::MediumAsteroid() {
//}

/////////////////////////////////////////////////////////////
//BigAsteroid::BigAsteroid() {
//}
