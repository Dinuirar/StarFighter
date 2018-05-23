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
    Q_OBJECT
public:
    CShip();
    CShip(QString MODEL, eWeaponID WEAPONID = PLASMA, int ID = 0,
         qreal X = 0, qreal Y = 0, qreal ANGLE = 0,
         qreal LINEAR_ACC = 0.1, qreal ANGULAR_ACC = 0.1,
         int HULL = 100, int SHIELDS = 100, int ENERGY = 100);
    eShipClass getType();
    eWeaponID getWeaponType();
    bool takeAHit(int, eWeaponID); // <<<<<<<<<<<<<<<<<<<<<< TODO
    void changeAngularSpeed(qreal val);
    void changeLinearSpeed(qreal val);
    void attack();
//    void getShipCounter() { return counterShip; }
    eLineOfSight isInLineOfSight();
    int id; // id statku
    QGraphicsScene* map;
public slots:
    void updateShip();
protected:
    QString modelName;
    eShipClass shipType;
    int energy, shields, hull;
    qreal linear_acceleration,
          radial_acceleration;
    eWeaponID we_id;
    void update();
private:
    int centerW, centerH;
    int counterShip;
    int prev_step;
};

#endif // SHIP_H
