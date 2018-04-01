#ifndef SHIP_H
#define SHIP_H

#include "common.h"
#include "cinertion.h"
#include "cweapons.h"

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>

// parametry statkow:
//  max. predkosc liniowa, katowa
//  przyspieszenie
//  hp, energia, tarcze
//  rozne moduly uzbrojenia ()

// grabKeyboard()

class CShip : public CInertion {
public:
    CShip();
    CShip(QString MODEL, weaponID WEAPONID, int ID,
         qreal X, qreal Y, qreal ANGLE,
         qreal LINEAR_ACC = 0, qreal ANGULAR_ACC = 0,
         int HULL = 100, int SHIELDS = 100, int ENERGY = 100);
    shipClass getType();
    weaponID getWeaponType();
    bool takeAHit(int, weaponID); // <<<<<<<<<<<<<<<<<<<<<< TODO
    void changeAngularSpeed(qreal val);
    void changeLinearSpeed(qreal val);
    void attack();
    lineOfSight isInLineOfSight();
    int id; // id statku
    QGraphicsScene* map;
protected:
    int dmg, special_dmg;
    QString modelName;
    shipClass shipType;
    int energy, shields, hull;
    qreal linear_acceleration,
          radial_acceleration;
    weaponID we_id;
private:
    void update();
    int centerW, centerH;
    int counter;
};

#endif // SHIP_H
