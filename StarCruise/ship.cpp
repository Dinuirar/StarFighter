#include "ship.h"
#include <iostream>
#include <cmath>

CShip::CShip() {
}

void CShip::update() {
    std::cout << "update " << counter << "\n";
    counter++;
    //    if ( counter%10 ){
    energy++;
    //        counter = 0;
    //    }
}

CShip::CShip(QString MODEL, weaponID WEAPONID, int ID,
           qreal X, qreal Y, qreal ANGLE,
           qreal LINEAR_ACC, qreal ANGULAR_ACC,
           int HULL, int SHIELDS, int ENERGY)
    : CInertion(X, Y, ANGLE), id(ID), modelName(MODEL),
      linear_acceleration(LINEAR_ACC), radial_acceleration(ANGULAR_ACC),
      energy(ENERGY), shields (SHIELDS), hull(HULL), we_id(WEAPONID) {
    QImage tmp(modelName);
    setPixmap( QPixmap::fromImage( tmp ) );
    centerW = tmp.width()/2;
    centerH = tmp.height()/2;
    setZValue(1);
    setTransformOriginPoint( centerW, centerH );
    setFlag(ItemIsFocusable);
    QTimer* timerShip = new QTimer(this);
    connect( timerShip, SIGNAL( timeout() ), this, SLOT( update() ) );
    timerShip->start(dt);
}

shipClass CShip::getType() {
    return shipType;
}

weaponID CShip::getWeaponType() {
    return we_id;
}

void CShip::changeAngularSpeed(qreal val) {
    CInertion::changeAngularSpeed(val);
}

void CShip::changeLinearSpeed(qreal val) {
    CInertion::changeLinearSpeed(val);
}

void CShip::attack() {
    std::cout << "energy: " << energy << "\n";
    qreal a = position.x() + centerW;
    qreal b = position.y() + centerH;
    if ( getWeaponType() == LASER ) {
        CLaser *engage = new CLaser(a, b, angle, -1);
        if( energy - engage->energyCost < 0 ) return;
        energy -= engage->energyCost;
        map->addItem(engage);
    }
    else if ( getWeaponType() == PLASMA ) {
        CPlasma *engage = new CPlasma(a, b, angle, -1);
        if( energy - engage->energyCost < 0 ) return;
        energy -= engage->energyCost;
        map->addItem(engage);
    }
    else if ( getWeaponType() == KINETIC ) {
        CKinetic *engage = new CKinetic(a, b, angle, -1);
        if( energy - engage->energyCost < 0 ) return;
        energy -= engage->energyCost;
        map->addItem(engage);
    }
}

lineOfSight CShip::isInLineOfSight() {
    // call checkLineOfSight() "attack"
    return NOTHING;
}
