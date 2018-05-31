#include "cbullet.h"

CBullet::CBullet() {
}

CBullet::CBullet(QPointF POSITION, qreal ANGLE,
                 EWeaponID TYPE, qreal RANGE)
    : CObject(POSITION.x(), POSITION.y(), ANGLE), range(RANGE) {
    this->setMaxLife( 10000 );
    this->setDamage( 10 );
    qreal lin_speed = 60;
    ANGLE = 3.14/2 - deg2rad(ANGLE);
    this->setLinearSpeed( QPointF( lin_speed*cos( ANGLE ), -lin_speed*sin( ANGLE ) ) );
}

