#include "ggraphics.h"
#include "common.h"

GGraphics::GGraphics( ) { }

GGraphics::GGraphics( QString MODELNAME, CObject * OBJECT ) {
    this->setModel( MODELNAME );
    this->setObject( OBJECT );
}

GGraphics::GGraphics(QString MODELNAME, CObject * OBJECT, qreal SCALE) {
    this->setModel(MODELNAME);
    this->setObject(OBJECT);
    this->setScale(SCALE);
}

void GGraphics::advance(int step) {
    if ( !step )
        return;
    if ( !fobject ) {
        start_cnt++;
        if ( start_cnt > 0 && start_cnt < 10)
            this->setModel( "../graphics/boom1.png" );
        else if ( start_cnt > 100 && start_cnt < 110 )
            this->setModel( "../graphics/boom2.png" );
        else if (start_cnt > 200 && start_cnt < 210 )
            this->setModel( "../graphics/boom3.png" );
        else if (start_cnt > 300)
            delete this;
    }
    else {
        setPos( fobject->getPosition().x(),
                fobject->getPosition().y() );
        setRotation( fobject->getAngle() );
    }

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
