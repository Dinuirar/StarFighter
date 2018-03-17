#include "ship.h"
#include <iostream>
#include <cmath>

ship::ship() {
    a = 0;
    b = 0;
    ang = 0;
    setFlag(ItemIsFocusable);
}

ship::ship(QPixmap pixitem) {
    a = 0;
    b = 0;
    ang = 0;
    setFlag(ItemIsFocusable);
    //setFlag(ItemIsMovable);
    setPixmap(pixitem);
}

void ship::keyPressEvent(QKeyEvent *event) {
    qreal step = 0.1;
    qreal radstep = 0.1;
    qreal dx = step * std::cos( 6.28/4 - ang * 0.01744 );
    qreal dy = step * std::sin( 6.28/4 - ang * 0.01744 );
    if( event->key() == Qt::Key_Down ) {
        setPos( a += dy, b += dx );
    }
    if( event->key() == Qt::Key_Up ) {
        setPos( a -= dx, b -= dy );
    }
    if( event->key() == Qt::Key_Right ) {
        setRotation(ang+=radstep);
    }
    if( event->key() == Qt::Key_Left ) {
        setRotation(ang-=radstep);
    }
}
