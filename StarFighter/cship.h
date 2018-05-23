#ifndef CSHIP_H
#define CSHIP_H

#include "cobject.h"
#include "common.h"

class CShip : public CObject {
public:
    CShip();
    CShip( EWeaponID WEAPONID = PLASMA, EId ID = NPC,
         qreal X = 0, qreal Y = 0, qreal ANGLE = 0,
         qreal LINEAR_ACC = 30, qreal ANGULAR_ACC = 8,
         int HULL = 100, int SHIELDS = 100, int ENERGY = 100 );
    void accelerateAngular(bool isClockwise);
    void accelerateLinear(bool isDecceleration = false);
    void attack();
    void decreaseHP();
    inline int getID() { return id; }
    void move() { return; }
private:
    EId id;
    int energy, shields;
    int counterShip;
    int centerW, centerH;
    qreal linear_acceleration;
    qreal angular_acceleration;
};

#endif // CSHIP_H
