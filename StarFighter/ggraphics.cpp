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
    setPos( fobject->getPosition().x(),
            fobject->getPosition().y() );
    setRotation( fobject->getAngle() );
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
