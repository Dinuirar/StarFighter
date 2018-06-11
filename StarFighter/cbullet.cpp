#include "cbullet.h"
#include "cship.h"
#include "casteroid.h"
#include "cspace.h"

CBullet::CBullet() {
}

CBullet::CBullet(QPointF POSITION, qreal ANGLE,
                 EWeaponID TYPE, qreal RANGE)
    : CObject(POSITION.x(), POSITION.y(), ANGLE),
      range(RANGE) {
    this->setSize( 5 );
    qreal lin_speed;
    if ( TYPE == LASER ) {
        this->setDmgValue( 10 );
        this->setMaxLife( 40 );
        lin_speed = 140;
    }
    else if ( TYPE == PLASMA) {
        this->setDmgValue( 20 );
        this->setMaxLife( 50 );
        lin_speed = 70;
    }
    else {
        this->setDmgValue( 5 );
        this->setMaxLife( 100 );
        lin_speed = 80;
    }
    ANGLE = 3.14/2 - deg2rad(ANGLE);
    this->setLinearSpeed( QPointF( lin_speed*cos( ANGLE ), -lin_speed*sin( ANGLE ) ) );
}

void CBullet::move() {
    if (cnt_lifetime > getMaxLife() )
        this->setDestroyObject();
    return;
}

void CBullet::collide(CObject * obj) {
    // deal damage to asteroid or ship
    if ( dynamic_cast<CShip*>( obj ) && this->getParent() != dynamic_cast<CShip*>( obj ) ) { // object is a ship
        dynamic_cast<CShip*>( obj )->reduceHP( this->getDmgValue() );
        this->setDestroyObject();
    }
    else if ( dynamic_cast<CAsteroid*>( obj ) ) { // object is an asteroid
        dynamic_cast<CAsteroid*>( obj )->reduceHP( this->getDmgValue()/2 );
        this->setDestroyObject();
    }
    else if ( dynamic_cast<CBullet*>( obj ) ) {
        return;
    }
    return;
}
