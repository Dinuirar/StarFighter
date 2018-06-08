#ifndef CSHIP_H
#define CSHIP_H

#include "cobject.h"
#include "common.h"
#include <deque>

class CShip : public CObject {
public:
    CShip();
    CShip( EWeaponID WEAPONID = PLASMA, EId ID = NPC,
         qreal X = 0, qreal Y = 0, qreal ANGLE = 0,
         qreal LINEAR_ACC = 30, qreal ANGULAR_ACC = 8,
         int HULL = 100, int SHIELDS = 100, int ENERGY = 100 );
    CShip( qreal size, EWeaponID WEAPONID = PLASMA, EId ID = NPC,
         CSpace* SPACE = NULL, QPoint POSITION = QPoint(10, 10), qreal ANGLE = 0,
         qreal LINEAR_ACC = 30, qreal ANGULAR_ACC = 8,
         int HULL = 100, int SHIELDS = 100, int ENERGY = 100, int FUEL = 1000 );
    ~CShip() {}
    void accelerateAngular(bool isClockwise);
    void accelerateLinear(bool isDecceleration = false);
    void attack();
    void decreaseHP();
    int getID();
    EWeaponID getWeaponType();
    int getEnergy();
    int getFuel();
    void move();
protected:
    void setEnergy(int _e);
    void setFuel(int _f);
    void setWeaponType( EWeaponID _w );
    int getAttackCost();
    void setAttackCost( int _c );
    void collide( CObject * );
private:
    EId id;
    EWeaponID weapon;
    int energy;
    int maxEnergy;
    int maxFuel;
    int fuel;
    int shields;
    int counterShip;
    int centerW, centerH;
    int attack_cost;
    qreal linear_acceleration;
    qreal angular_acceleration;
};

#endif // CSHIP_H
