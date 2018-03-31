#include "ship.h"
#include <iostream>
#include <cmath>

ship::ship() {
}

ship::ship(QString MODEL, int ID,
           qreal X, qreal Y, qreal ANGLE,
           qreal LINEAR_SPEED, qreal ANGULAR_SPEED,
           int HULL, int SHIELDS, int ENERGY)
    : CInertion(X, Y, ANGLE, LINEAR_SPEED, ANGULAR_SPEED),
      id(ID), modelName(MODEL),
      energy(ENERGY), shields (SHIELDS), hull(HULL) {
    QImage tmp(modelName);
    setPixmap( QPixmap::fromImage( tmp ) );
    int centerW = tmp.width()/2,
        centerH = tmp.height()/2;
    setTransformOriginPoint( centerW, centerH );
    setFlag(ItemIsFocusable);
}

void ship::keyPressEvent(QKeyEvent *event) {
    if (id == 1){
        if( event->key() == Qt::Key_S ) {
            changeLinearSpeed( -0.1 );
        }
        if( event->key() == Qt::Key_W ) {
            changeLinearSpeed( 0.1 );
        }
        if( event->key() == Qt::Key_D ) {
            changeAngularSpeed( 0.1 );
        }
        if( event->key() == Qt::Key_A ) {
            changeAngularSpeed( -0.1 );
        }
    }

    if (id == 2){
        if( event->key() == Qt::Key_Down ) {
            changeLinearSpeed( -0.1 );
        }
        if( event->key() == Qt::Key_Up ) {
            changeLinearSpeed( 0.1 );
        }
        if( event->key() == Qt::Key_Right ) {
            changeAngularSpeed( 0.1 );
        }
        if( event->key() == Qt::Key_Left ) {
            changeAngularSpeed( -0.1 );
        }
    }
}
