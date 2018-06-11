#include "casteroid.h"
#include "cbullet.h"
#include "cship.h"

CAsteroid::CAsteroid() {
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

void CAsteroid::move() {
}

void CAsteroid::collide(CObject * obj) {
    // do nothing with bullet
    if ( dynamic_cast<CBullet*>( obj ) ) {
        return;
    }
    // take some of the ship's speed
    else if ( dynamic_cast<CShip*>( obj ) ) {
        this->setLinearSpeed( -this->getLinearSpeed() + 0.1*dynamic_cast<CShip*>( obj )->getLinearSpeed() );
        dynamic_cast<CShip*>( obj )->reduceHP( 25 );
    }
    // bounce from the other asteroid
    else if ( dynamic_cast<CAsteroid*>( obj ) ) {
        this->setLinearSpeed( -this->getLinearSpeed() );
    }
    return;
}
