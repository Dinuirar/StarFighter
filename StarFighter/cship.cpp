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
    this->setHP(HULL);
}

CShip::CShip(qreal size, EWeaponID WEAPONID, EId ID, CSpace *SPACE, QPoint POSITION, qreal ANGLE, qreal LINEAR_ACC, qreal ANGULAR_ACC, int HULL, int SHIELDS, int ENERGY)
    : CObject( POSITION.x(), POSITION.y(), ANGLE, 0, 0, 0),
      linear_acceleration(LINEAR_ACC), angular_acceleration(ANGULAR_ACC),
      shields(SHIELDS), energy(ENERGY), id(ID), weapon(WEAPONID) {
    this->setHP(HULL);
    this->setSpace(SPACE);
    this->setSize(size);
}

void CShip::accelerateAngular(bool plus) {
    if(plus) {
        angular_speed += dt * angular_acceleration;
    }
    else {
        angular_speed -= dt * angular_acceleration;
    }
}

void CShip::accelerateLinear(bool isDecceleration) {
    if ( !isDecceleration ) {
//        if( linear_speed.x()*linear_speed.x() + linear_speed.y()*linear_speed.y() > MAX_LIN_SPEED_SQR ) {
//            if (    (linear_speed.ry() - linear_acceleration * dt * cos( angle * 0.01744 )) *  (linear_speed.ry() - linear_acceleration * dt * cos( angle * 0.01744 ))
//                    +
//                    (linear_speed.rx() + linear_acceleration * dt * sin( angle * 0.01744 )) * (linear_speed.rx() + linear_acceleration * dt * sin( angle * 0.01744 )) > MAX_LIN_SPEED_SQR
//                    )
//                return;
//        }
        linear_speed.ry() -= linear_acceleration * dt * cos( getAngle() * 0.01744 );
        linear_speed.rx() += linear_acceleration * dt * sin( getAngle() * 0.01744 );
    }
    else {
//        if( linear_speed.x()*linear_speed.x() + linear_speed.y()*linear_speed.y() > MAX_LIN_SPEED_SQR ) {
//            if (    (linear_speed.ry() + linear_acceleration * dt * cos( angle * 0.01744 )) *  (linear_speed.ry() + linear_acceleration * dt * cos( angle * 0.01744 ))
//                    +
//                    (linear_speed.rx() - linear_acceleration * dt * sin( angle * 0.01744 )) * (linear_speed.rx() - linear_acceleration * dt * sin( angle * 0.01744 )) > MAX_LIN_SPEED_SQR
//                    )
//                return;
//        }
        linear_speed.ry() += linear_acceleration * dt * cos( getAngle() * 0.01744 );
        linear_speed.rx() -= linear_acceleration * dt * sin( getAngle() * 0.01744 );
    }
}

void CShip::attack() {
    if( !this->getSpace() )
        return;
//    if ( energy )
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
    energy++;
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

int CShip::getEnergy() {
    return energy;
}

void CShip::setEnergy(int _e) {
    energy = _e;
}
