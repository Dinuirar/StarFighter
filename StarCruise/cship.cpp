#include "cship.h"
#include <iostream>
#include <cmath>

CShip::CShip() { }

/// update ship's position
void CShip::update() {
    inertionCounter++;
    qreal step = linear_speed * dt;
    qreal dx = step * std::cos( 3.14/2 - angle * 0.01744 );
    qreal dy = step * std::sin( 3.14/2 - angle * 0.01744 );
    position.rx() -= dx;
    position.ry() += dy;

    qreal thresh = 0.0001;
    if ( position.x() + centerW < thresh &&
         position.y() + centerH < thresh ){ // top left corner
        setPos( -centerW, -centerH );
    }
    else if ( position.x() + centerW - windowWidth > thresh &&
              position.y() + centerH < thresh) { // top right corner
        setPos ( -centerW + windowWidth, -centerH );
    }
    else if ( position.x() + centerW < thresh &&
              position.y() + centerH - windowHeight > thresh ) { // bottom left corner
        setPos( -centerW, -centerH + windowHeight );
    }
    else if ( position.x() + centerW - windowWidth > thresh &&
              position.y() + centerH - windowHeight > thresh ) { // bottom right corner
        setPos( -centerW + windowWidth, -centerH + windowHeight );
    }
    else if ( position.x() + centerW < thresh ) { // left edge
        setPos( -centerW, position.y() );
    }
    else if (position.y() + centerH < thresh ) { // upper edge
        setPos( position.x(), -centerH );
    }
    else if ( position.x() + centerW - windowWidth > thresh ) { // right edge
        setPos( windowWidth - centerW , position.y() );
    }
    else if ( position.y() + centerH - windowHeight > thresh  ) { // bottom edge
        setPos( position.x(), windowHeight - centerH );
    }
    else {
        setPos( position.x(), position.y() );
    }

    qreal radstep = angular_speed * dt;
    angle += radstep;
    setRotation(angle);
}

/// update ship's status (raise energy etc.)
void CShip::updateShip() {
    //std::cout << "update cS: " << counterShip << "\n";
    counterShip++;
    if ( energy >= 100 ) return;
    if ( !(counterShip % 10) ){
        energy++;
    }
}

CShip::CShip(QString MODEL, eWeaponID WEAPONID, int ID,
           qreal X, qreal Y, qreal ANGLE,
           qreal LINEAR_ACC, qreal ANGULAR_ACC,
           int HULL, int SHIELDS, int ENERGY)
    : CInertion(X, Y, ANGLE), id(ID), modelName(MODEL),
      linear_acceleration(LINEAR_ACC), radial_acceleration(ANGULAR_ACC),
      energy(ENERGY), shields (SHIELDS), hull(HULL), we_id(WEAPONID),
      counterShip(0), prev_step(0) {
    QImage tmp(modelName);
    setPixmap( QPixmap::fromImage( tmp ) );
    centerW = tmp.width() / 2.;
    centerH = tmp.height() / 2.;
    setZValue(1);
    setTransformOriginPoint( centerW, centerH );
    setFlag(ItemIsFocusable);

    QTimer* timerShip = new QTimer(this);
    connect( timerShip, SIGNAL( timeout() ), this, SLOT( updateShip() ) );
    timerShip->start(dt);
}

eShipClass CShip::getType() {
    return shipType;
}

eWeaponID CShip::getWeaponType() {
    return we_id;
}

void CShip::changeAngularSpeed(qreal val) {
    CInertion::changeAngularSpeed(val);
}

void CShip::changeLinearSpeed(qreal val) {
    CInertion::changeLinearSpeed(val);
}

void CShip::attack() {
    std::cout << "energy: " << energy
              << " counter: " << inertionCounter << "\n";
    qreal a = position.x() + centerW;
    qreal b = position.y() + centerH;
    if ( getWeaponType() == LASER ) {
        CLaser *engage = new CLaser(a, b, angle);
        if ( inertionCounter - prev_step < engage->delay() )
            return;
        else
            prev_step = inertionCounter;
        if( energy - engage->energyCost() < 0 ) return;
        energy -= engage->energyCost();
        map->addItem(engage);
    }
    else if ( getWeaponType() == PLASMA ) {
        CPlasma *engage = new CPlasma(a, b, angle);
        if (inertionCounter - prev_step < engage->delay())
            return;
        else
            prev_step = inertionCounter;
        if( energy - engage->energyCost() < 0 ) return;
        energy -= engage->energyCost();
        map->addItem(engage);
    }
    else if ( getWeaponType() == KINETIC ) {
        CKinetic *engage = new CKinetic(a, b, angle);
        if (inertionCounter - prev_step < engage->delay())
            return;
        else
            prev_step = inertionCounter;
        if( energy - engage->energyCost() < 0 ) return;
        energy -= engage->energyCost();
        map->addItem(engage);
    }
}

eLineOfSight CShip::isInLineOfSight() {
    // call checkLineOfSight() "attack"
    return NOTHING;
}
