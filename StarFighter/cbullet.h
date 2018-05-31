#ifndef CBULLET_H
#define CBULLET_H

#include "cobject.h"
#include "common.h"

class CBullet : public CObject {
public:
    CBullet();
    CBullet(QPointF POSITION, qreal ANGLE,
            EWeaponID TYPE, qreal RANGE = 10);
    qreal getRange() { return range; }
    void setRange(qreal _r) { range = _r; }
    EWeaponID getType() { return type; }
    void setType(EWeaponID _type) { type = _type; }
    int getDamage() { return damage; }
    void setDamage( int _d ) { damage = _d; }
    void move() { return; }
private:
    qreal range;
    EWeaponID type;
    int damage;
};

#endif // CBULLET_H
