#include "ggraphics.h"
#include "common.h"

GGraphics::GGraphics( ) { }

GGraphics::GGraphics( QString MODELNAME, CObject * OBJECT ) {
    setModel(MODELNAME);
    setObject(OBJECT);
}

void GGraphics::advance(int step) {
    if ( !step )
        return;
    qreal* fposX = &fobject->position.rx();
    qreal* fposY = &fobject->position.ry();
    if ( *fposX < 0 ) {
        *fposX = WINDOW_WIDTH;
    }
    else if ( *fposX > WINDOW_WIDTH ) {
        *fposX = 0;
    }
    if ( *fposY < 0 ) {
        *fposY = WINDOW_HEIGHT;
    }
    else if ( *fposY > WINDOW_HEIGHT ) {
        *fposY = 0;
    }
    setPos( fobject->position.rx() += dt * fobject->linear_speed.x(),
            fobject->position.ry() += dt * fobject->linear_speed.y() );
    setRotation( fobject->angle += dt * fobject->angular_speed );
}

void GGraphics::setModel( QString p_name ) {
    QImage* tmp = new QImage( p_name );
    setPixmap( QPixmap::fromImage( *tmp ));
//    setZValue(1);
    centerW = tmp->width() / 2.;
    centerH = tmp->height() / 2.;
    //setTransformOriginPoint( centerW, centerH );
    setOffset( -centerW, -centerH );
}
