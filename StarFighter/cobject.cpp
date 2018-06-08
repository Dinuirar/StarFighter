#include "cobject.h"
#include "cspace.h"
#include "casteroid.h"
#include "cbullet.h"

CObject::CObject() {
}

CObject::CObject(qreal X, qreal Y, qreal ANGLE,
                 qreal LINEAR_SPEEDX, qreal LINEAR_SPEEDY, qreal ANGULAR_SPEED)
    : position( QPoint(X, Y) ), angle(ANGLE),
      linear_speed( QPointF(LINEAR_SPEEDX, LINEAR_SPEEDY) ),
      angular_speed(ANGULAR_SPEED),
      cnt_lifetime(0) {
    hitpoints = 30;
    size = 10;
    FSpace = NULL;
    destroy = false;
    colliding = false;
}

CObject::~CObject() {
}

qreal CObject::calcDistance(CObject * _obj) {
    QPointF tmp = this->getPosition() - _obj->getPosition();
    return sqrt( tmp.x() * tmp.x() + tmp.y() * tmp.y() );
}

void CObject::update() {
    if ( this->getHP() <= 0 ) {
        this->removeObject();
    }

    if ( position.x() < 0 ) {
        position.rx() = WINDOW_WIDTH;
    }
    else if ( position.x() > WINDOW_WIDTH ) {
        position.rx() = 0;
    }
    if ( position.y() < 0 ) {
        position.ry() = WINDOW_HEIGHT;
    }
    else if ( position.y() > WINDOW_HEIGHT ) {
        position.ry() = 0;
    }

    objs = getSpace()->getObjInRange( this, this->getSize() );
    if ( objs.size() == 1 || dynamic_cast<CBullet*>( this ) ) {
        colliding = false;
    }
    else {
        colliding = true;
//        this->collide( );
//        CObject* collide;
//        for ( u_int i = 0; i < objs.size(); i++ ) {
//            if ( dynamic_cast<CObject*>( this ) != objs[i] ) {
//                collide = objs[i];
//            }
//        }
//        if ( dynamic_cast<CAsteroid*>( collide ) ) {

//        }
    }


    if ( colliding ) {
        reduceHP( 1 );
//        if ( ! dynamic_cast<CAsteroid*>( this ) ) {
//            // change linear_speed
//            for ( u_int i = 0; i < objs.size(); i++ ) {
//                if( (CObject*)this != objs[i] ) {
////                    this->setLinearSpeed( (-1) * this->getLinearSpeed() );
//                    this->setLinearSpeed( QPointF(0, 0) );
//                    this->setAngularSpeed( 0 );
//                }
//            }
//        }
    }

    this->setPosition( this->getPosition() + dt * this->getLinearSpeed() );
    this->setAngle( this->getAngle() + dt * this->getAngularSpeed() );

//    if ( objs.size() == 1 || dynamic_cast<CBullet*>( this ) ) {
//        this->setPosition( this->getPosition() + dt * this->getLinearSpeed() );
//        this->setAngle( this->getAngle() + dt * this->getAngularSpeed() );
//    }
//    else { // collision?
//        colliding = true;
//        for ( u_int i = 0; i < objs.size(); i++ ) {
//            if( this != objs[i] ) {
////                this->reduceHP(1);
////                objs[i]->reduceHP(1);
//                this->linear_speed = -linear_speed;
//                return;
//            }
//        }
//    }
    cnt_lifetime++;
}

void CObject::setAngularSpeed(qreal _v) {
    angular_speed = _v;
}

void CObject::setPosition(QPointF _p) {
    position = _p;
}

void CObject::setAngle(qreal _a) {
    angle = _a;
}

void CObject::setLinearSpeed(QPointF _l) {
    linear_speed = _l;
}

qreal CObject::getAngularSpeed() {
    return angular_speed;
}

QPointF CObject::getLinearSpeed() {
    return linear_speed;
}

QPointF CObject::getPosition() {
    return position;
}

qreal CObject::getAngle() {
    return angle;
}

void CObject::setSpace(CSpace* _s) {
    FSpace = _s;
}

CSpace* CObject::getSpace() {
    return FSpace;
}

int CObject::getLifetime() {
    return cnt_lifetime;
}

void CObject::removeObject() {
    destroy = true;
}

bool CObject::isToDestroy() {
    return destroy;
}

void CObject::unremoveObject() {
    destroy = false;
}

void CObject::reduceHP( int dmg ) {
    hitpoints -= dmg;
}

int CObject::getHP() {
    return hitpoints;
}

void CObject::setHP( int hp) {
    hitpoints = hp;
}
