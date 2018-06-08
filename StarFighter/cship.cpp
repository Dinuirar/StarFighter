#include "cship.h"
#include "cspace.h"
#include "cbullet.h"
#include "ggraphics.h"
#include <cmath>

CShip::CShip() {
}

CShip::CShip( EWeaponID WEAPONID, EId ID,
             qreal X, qreal Y, qreal ANGLE,
             qreal LINEAR_ACC, qreal ANGULAR_ACC,
             int HULL, int SHIELDS, int ENERGY)
    : CObject( X, Y, ANGLE, 0, 0, 0),
      linear_acceleration(LINEAR_ACC), angular_acceleration(ANGULAR_ACC),
      shields(SHIELDS), energy(ENERGY),  id(ID), weapon(WEAPONID) {
    this->setFuel(0);
    this->setAttackCost(50);
    this->setSpace(NULL);
    this->setHP(HULL);
}

CShip::CShip(qreal size, EWeaponID WEAPONID, EId ID,
             CSpace *SPACE, QPoint POSITION, qreal ANGLE,
             qreal LINEAR_ACC, qreal ANGULAR_ACC,
             int HULL, int SHIELDS, int ENERGY, int MAXFUEL)
    : CObject( POSITION.x(), POSITION.y(), ANGLE, 0, 0, 0),
      linear_acceleration(LINEAR_ACC), angular_acceleration(ANGULAR_ACC),
      shields(SHIELDS), energy(ENERGY), id(ID), weapon(WEAPONID), maxFuel(MAXFUEL) {
    this->setFuel( this->maxFuel );
    this->setHP(HULL);
    this->setSpace(SPACE);
    this->setSize(size);
    if ( this->getID() == LASER ) {
        this->setAttackCost( laser_energy_cost );
    }
    else if ( this->getID() == PLASMA ) {
        this->setAttackCost( plasma_energy_cost );
    }
    else {
        this->setAttackCost( kinetic_energy_cost );
    }
}

void CShip::accelerateAngular(bool plus) {
    if ( this->getFuel() <= 0 ) return;
    fuel--;
    if(plus) {
        angular_speed += dt * angular_acceleration;
    }
    else {
        angular_speed -= dt * angular_acceleration;
    }
}

void CShip::accelerateLinear(bool isDecceleration) {
    if ( this->getFuel() <= 0 ) return;
    fuel--;
    if ( !isDecceleration ) {
        linear_speed.ry() -= linear_acceleration * dt * cos( getAngle() * 0.01744 );
        linear_speed.rx() += linear_acceleration * dt * sin( getAngle() * 0.01744 );
    }
    else {
        linear_speed.ry() += linear_acceleration * dt * cos( getAngle() * 0.01744 );
        linear_speed.rx() -= linear_acceleration * dt * sin( getAngle() * 0.01744 );
    }
}

void CShip::attack() {
    if( !this->getSpace() )
        return;
    if ( this->getEnergy() < this->getAttackCost() )
        return;
    energy -= this->getAttackCost();
    GGraphics* bullet_g;
    EWeaponID bullet_type = this->getWeaponType();
    CBullet* bullet = new CBullet(this->getPosition(), this->getAngle(),
                     bullet_type);
    if ( bullet_type == LASER ) {
        bullet_g = new GGraphics( "../graphics/laser.png", bullet );
    }
    else if ( bullet_type == PLASMA  ) {
        bullet_g = new GGraphics("../graphics/plasma.png", bullet);
    }
    else if ( bullet_type == KINETIC ) {
        bullet_g = new GGraphics("../graphics/kinetic.png", bullet);
    }
    else
        return;
    if( !bullet_g )
        return;
    bullet_g->setScale(0.2);
    bullet->setSpace( this->getSpace() );
    bullet->setParent( this );
    this->getSpace()->addObject(bullet, bullet_g);
}

void CShip::move() {
    maxEnergy = int( double(fuel) / maxFuel * 100 );
    if ( this->getLifetime() % 7 == 0 ) {
        if ( energy < maxEnergy )
            energy++;
        if ( !( this->getFuel() <= 0 ) )
            fuel--;
    }
    // std::deque<CObject*> list = getSpace()->getObjInRange(this);
    // jesli statek jest autonomiczny - podejmij decyzje na podstawie obiektow w zasiegu
    return;
}

int CShip::getID() {
    return id;
}

EWeaponID CShip::getWeaponType() {
    return weapon;
}

void CShip::setWeaponType( EWeaponID _w ) {
    weapon = _w;
}

int CShip::getAttackCost() {
    return attack_cost;
}

void CShip::setAttackCost(int _c) {
    attack_cost = _c;
}

void CShip::collide(CObject *) {
    // do nothing with bullet
    // bounce from the asteroid
    // bounce from the other ship
}

int CShip::getEnergy() {
    return energy;
}

int CShip::getFuel() {
    return fuel;
}

void CShip::setEnergy(int _e) {
    energy = _e;
}

void CShip::setFuel(int _f) {
    fuel = _f;
}


