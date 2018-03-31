#ifndef SHIP_H
#define SHIP_H

#include "common.h"
#include "cinertion.h"

#include <QGraphicsPixmapItem>
#include <QKeyEvent>

// parametry statkow:
//  max. predkosc liniowa, katowa
//  przyspieszenie
//  hp, energia, tarcze
//  rozne moduly uzbrojenia ()

// grabKeyboard()

class ship : public CInertion {
public:
    ship();
    ship(QString MODEL, int ID,
         qreal X, qreal Y, qreal ANGLE,
         qreal LINEAR_SPEED = 0, qreal ANGULAR_SPEED = 0,
         int HULL = 100, int SHIELDS = 100, int ENERGY = 100);
    void keyPressEvent(QKeyEvent *event);
    shipClass getType(); // <<<<<<<<<<<<<<<<<<<<<< TODO
    bool takeAHit(int, attackType); // <<<<<<<<<<<<<<<<<<<<<< TODO
protected:
    int id; // id statku
    int energy, shields, hull;
    QString modelName;
    //virtual void move(Qt::Key); // <<<<<<<<<<<<<<<<<<<<<< TODO
    //virtual void attack(int); // <<<<<<<<<<<<<<<<<<<<<< TODO
    //virtual void specialAttack(int); // <<<<<<<<<<<<<<<<<<<<<< TODO
};

#endif // SHIP_H
