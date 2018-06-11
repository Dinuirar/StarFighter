#include "cship.h"
#include "cspace.h"
#include "cbullet.h"
#include "casteroid.h"
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
    // jesli statek jest autonomiczny - podejmij decyzje na podstawie obiektow w zasiegu
//    if ( this->getID() == NPC ) {
//      checkLineOfSight();
//        for ( u_int i = 0; i < objs.size(); i++) {

//        }

//    }
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

CObject *CShip::checkLineOfSight(qreal& distance) {
//    std::deque<CObject*> line = this->getSpace()->getObjInRange(this, 250);
//    std::vector<qreal> distances;
//    for (u_int i = 0; i < line.size(); i++) {
//        if ( dynamic_cast<CObject*>(this) != line[i] )
//            distances.push_back( -1 );
//        distances.push_back( this->calcDistance(line[i]) );
//    }
//    distance = distances[0];
//    int close_index = 0;
//    for ( u_int i = 0; i < line.size(); i++ ) {
//        if ( distances[i] < distance ) {
//            distance = distances[i];
//            close_index = i;
//        }
//    }
//    return line[close_index];
}

void CShip::collide(CObject * obj) {
    // do nothing with a bullet
    if ( dynamic_cast<CBullet*>( obj ) ) {
        return;
    }
    // bounce from the other ship
    else if ( dynamic_cast<CShip*>( obj ) ) {
        this->setLinearSpeed( -this->getLinearSpeed()*0.9 );
    }
    // bounce from the asteroid
    else if ( dynamic_cast<CAsteroid*>( obj ) ) {
        this->setLinearSpeed( -this->getLinearSpeed()*0.9 );
        this->reduceHP( 25 );
    }
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


