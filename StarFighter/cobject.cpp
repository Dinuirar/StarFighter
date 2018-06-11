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
        this->setDestroyObject();
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

    objs.clear();
    objs = getSpace()->getObjInRange( this, this->getSize() );
    if ( objs.size() == 1 ) {
        colliding = false;
    }
    else {
        colliding = true;
        for ( u_int i = 0; i < objs.size(); i++ ) {
            if( objs[i] != dynamic_cast<CObject*>( this ) ) {
                //this->collide( objs[i] );
                objs[i]->collide( this );
                break;
            }
        }
    }

    this->setPosition( this->getPosition() + dt * this->getLinearSpeed() );
    this->setAngle( this->getAngle() + dt * this->getAngularSpeed() );

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

void CObject::setDestroyObject() {
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
