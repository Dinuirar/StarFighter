#ifndef CBULLET_H
#define CBULLET_H

#include "cobject.h"
#include "common.h"

class CShip;

class CBullet : public CObject {
public:
    CBullet();
    CBullet(QPointF POSITION, qreal ANGLE,
            EWeaponID TYPE, qreal RANGE = 50);
    ~CBullet() {}
    qreal getRange() { return range; }
    void setRange(qreal _r) { range = _r; }
    EWeaponID getType() { return type; }
    void setType(EWeaponID _type) { type = _type; }
    int getDmgValue() { return damage; }
    void setDmgValue( int _d ) { damage = _d; }
    int getMaxLife() { return MAXLIFETIME; }
    void setMaxLife( int _m ) { MAXLIFETIME = _m; }
    void setParent( CShip* _parent ) { parent = _parent; }
    CShip* getParent() { return parent; }
    void move();
protected:
    void collide( CObject * );
private:
    CShip* parent;
    int MAXLIFETIME;
    qreal range;
    EWeaponID type;
    int damage;
};

#endif // CBULLET_H
