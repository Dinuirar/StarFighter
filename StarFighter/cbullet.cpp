#include "cbullet.h"

CBullet::CBullet() {
}

CBullet::CBullet(QPointF POSITION, qreal ANGLE,
                 EWeaponID TYPE, qreal RANGE)
    : CObject(POSITION.x(), POSITION.y(), ANGLE), range(RANGE) {
    qreal lin = 10;
    this->setLinearSpeed( QPointF( lin*sin(ANGLE), lin*cos(ANGLE) ) );
}

