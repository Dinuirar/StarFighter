#include "cship.h"
#include <cmath>

CShip::CShip() {
}

CShip::CShip( EWeaponID WEAPONID, EId ID,
             qreal X, qreal Y, qreal ANGLE,
             qreal LINEAR_ACC, qreal ANGULAR_ACC,
             int HULL, int SHIELDS, int ENERGY)
    : CObject( X, Y, ANGLE, 0, 0, 0),
      linear_acceleration(LINEAR_ACC), angular_acceleration(ANGULAR_ACC),
      shields(SHIELDS), energy(ENERGY),  id(ID) {
}

void CShip::accelerateAngular(bool plus) {
    if(plus) {
        if (angular_speed > MAX_ANG_SPEED)
            if (angular_speed + dt > MAX_ANG_SPEED)
                return;
        angular_speed += dt * angular_acceleration;
    }
    else {
        if (angular_speed > MAX_ANG_SPEED)
            if (angular_speed - dt > MAX_ANG_SPEED)
                return;
        angular_speed -= dt * angular_acceleration;
    }
}

void CShip::accelerateLinear(bool isDecceleration) {
    if ( !isDecceleration ) {
        if( linear_speed.x()*linear_speed.x() + linear_speed.y()*linear_speed.y() > MAX_LIN_SPEED_SQR ) {
            if (    (linear_speed.ry() - linear_acceleration * dt * cos( angle * 0.01744 )) *  (linear_speed.ry() - linear_acceleration * dt * cos( angle * 0.01744 ))
                    +
                    (linear_speed.rx() + linear_acceleration * dt * sin( angle * 0.01744 )) * (linear_speed.rx() + linear_acceleration * dt * sin( angle * 0.01744 )) > MAX_LIN_SPEED_SQR
                    )
                return;
        }
        linear_speed.ry() -= linear_acceleration * dt * cos( angle * 0.01744 );
        linear_speed.rx() += linear_acceleration * dt * sin( angle * 0.01744 );
    }
    else {
        if( linear_speed.x()*linear_speed.x() + linear_speed.y()*linear_speed.y() > MAX_LIN_SPEED_SQR ) {
            if (    (linear_speed.ry() + linear_acceleration * dt * cos( angle * 0.01744 )) *  (linear_speed.ry() + linear_acceleration * dt * cos( angle * 0.01744 ))
                    +
                    (linear_speed.rx() - linear_acceleration * dt * sin( angle * 0.01744 )) * (linear_speed.rx() - linear_acceleration * dt * sin( angle * 0.01744 )) > MAX_LIN_SPEED_SQR
                    )
                return;
        }
        linear_speed.ry() += linear_acceleration * dt * cos( angle * 0.01744 );
        linear_speed.rx() -= linear_acceleration * dt * sin( angle * 0.01744 );
    }
}

void CShip::attack() {
    // add create object: bullet
}
