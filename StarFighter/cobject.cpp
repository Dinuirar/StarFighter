#include "cobject.h"

CObject::CObject() {
}

CObject::CObject(qreal X, qreal Y, qreal ANGLE,
                 qreal LINEAR_SPEEDX, qreal LINEAR_SPEEDY, qreal ANGULAR_SPEED)
    : position( QPoint(X, Y) ), angle(ANGLE),
      linear_speed( QPointF(LINEAR_SPEEDX, LINEAR_SPEEDY) ),
      angular_speed(ANGULAR_SPEED),
      cnt_lifetime(0) {

}

//void CObject::advance(int step) {
//}
