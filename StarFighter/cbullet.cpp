#include "cbullet.h"
#include "cship.h"
#include "cspace.h"

CBullet::CBullet() {
}

CBullet::CBullet(QPointF POSITION, qreal ANGLE,
                 EWeaponID TYPE, qreal RANGE)
    : CObject(POSITION.x(), POSITION.y(), ANGLE),
      range(RANGE) {
    this->setMaxLife( 100 );
    this->setDmgValue( 10 );
    qreal lin_speed = 60;
    ANGLE = 3.14/2 - deg2rad(ANGLE);
    this->setLinearSpeed( QPointF( lin_speed*cos( ANGLE ), -lin_speed*sin( ANGLE ) ) );
}

void CBullet::move() {
    std::deque<CObject*> objsInRange;
    objsInRange = getSpace()->getObjInRange( this, range );
    for (u_int i = 0; i < objsInRange.size(); i++) {
        if (objsInRange[i]->getPosition() != this->getPosition()
         && objsInRange[i]->getPosition() != this->getParent()->getPosition()
         && !dynamic_cast<CBullet*>(objsInRange[i]) ) {
            objsInRange[i]->reduceHP( damage );
            this->removeObject();
        }
    }

    if (cnt_lifetime > getMaxLife() )
        this->removeObject();
    return;
}
