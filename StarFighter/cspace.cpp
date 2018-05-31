#include "cspace.h"
#include "cbullet.h"

CSpace::CSpace() {
    setSceneRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    setBackgroundBrush( QImage( SPACE_BACKGROUND )  );

    QGraphicsPixmapItem* coordinates = new QGraphicsPixmapItem(
                QPixmap::fromImage(
                    QImage( "../graphics/coordinates.png" )
                    )
                );
    coordinates->setPos(0, 0);
    coordinates->setZValue(2);
    addItem(coordinates);
}

std::deque<CObject*> CSpace::getObjInRange(CObject *_obj, qreal _range) {
    std::deque<CObject*> objInRange;
    for (int i = 0; i < FListObj.size(); i++) {
        if ( _obj->calcDistance(FListObj[i]) <= _range )
            objInRange.push_back(FListObj[i]);
    }
    return objInRange;
}

void CSpace::addObject(CObject * _obj, GGraphics * _graphic) {
    addItem(_graphic);
    FListObj.push_back(_obj);
    FListGraphics.push_back(_graphic);
}

void CSpace::updateObjs() {
    for (int i = 0; i < FListObj.size(); i++) {
//        FListObj[i]->update();
        if( dynamic_cast<CBullet*>( FListObj[i] ) &&
            dynamic_cast<CBullet*>( FListObj[i] )->getMaxLife() < FListObj[i]->getLifetime() ) { // cast object on bullet, check its lifetime
            //deleteObject(i);
            //const std::deque<CObject*>::iterator _iposition = FListObj.at(i);
            //FListObj.erase( _iposition );
            //delete FListObj[i];
            //delete FListGraphics[i];
            // FListObj.at(i);
        }
        else {
            FListObj[i]->update();
        }
    }
}
