#include "cspace.h"
#include "cbullet.h"

void initIndicator(QGraphicsSimpleTextItem * &indicator, QColor color, qreal posX, qreal posY) {
    indicator = new QGraphicsSimpleTextItem();
    indicator->setZValue(3);
    indicator->setFont( QFont("Helvetica", 17) );
    indicator->setBrush( color );
    indicator->setPos( posX, posY );
}

CSpace::CSpace() {
    setSceneRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    setBackgroundBrush( QImage( SPACE_BACKGROUND )  );

    QColor player_color = QColor(0, 0, 255, 127);

    int indicatorsX1 = 80,
            indicatorsY1 = 10,
            indicatorsY2 = 30,
            indicatorsY3 = 50;

    initIndicator( hp_indicator, player_color, indicatorsX1, indicatorsY1 );
    this->addItem( hp_indicator );
    initIndicator( fuel_indicator, player_color, indicatorsX1, indicatorsY2 );
    this->addItem( fuel_indicator );
    initIndicator( energy_indicator, player_color, indicatorsX1, indicatorsY3 );
    this->addItem( energy_indicator );
}

std::deque<CObject*> CSpace::getObjInRange(CObject *_obj, qreal _range) {
    std::deque<CObject*> objInRange;
    for (u_int i = 0; i < FListObj.size(); i++) {
        if( _obj->calcDistance(FListObj[i]) <= _range + FListObj[i]->getSize() )
            objInRange.push_back(FListObj[i]);
    }
    return objInRange;
}

void CSpace::addObject(CObject * _obj, GGraphics * _graphic) {
    addItem(_graphic);
    FListObj.push_back(_obj);
    FListGraphics.push_back(_graphic);

    if ( !player ) {
        CShip* tmp = dynamic_cast<CShip*>( _obj );
        if( !tmp ) return;
        if( tmp->getID() == PLAYER ) player = tmp;
    }
}

void CSpace::removeObject( u_int index ) {
    QGraphicsItem* _item = FListGraphics[index];
    if ( _item )
        removeItem(_item);
    CShip* tmp = dynamic_cast<CShip*>( FListObj[index] );
    if ( tmp ) {
        if (tmp->getID() == PLAYER )
            player = NULL;
        else
            enemy = NULL;
    }
    std::deque<CObject*>::iterator _iposition = FListObj.begin();
    std::deque<GGraphics*>::iterator __iposition = FListGraphics.begin();
    for (u_int i = 0; i < index; i++) {
        _iposition++;
        __iposition++;
    }
    delete FListObj[index];
//    FListGraphics[index]->setObject( NULL );
    delete FListGraphics[index];
    FListObj.erase(_iposition);
    FListGraphics.erase(__iposition);
}

void CSpace::updateObjs() {
    if( player ) {
        playerHP = QString::number( player->getHP() );
        playerFuel = QString::number( player->getFuel() );
        playerEnergy = QString::number( player->getEnergy() );
        hp_indicator->setText( "hull: " + playerHP );
        fuel_indicator->setText( "fuel: " + playerFuel );
        energy_indicator->setText( "energy: " + playerEnergy );
    }
    else {
        hp_indicator->setText( destroyedMessage );
        energy_indicator->setText( destroyedMessage );
        fuel_indicator->setText( destroyedMessage );
    }

    for (u_int i = 0; i < FListObj.size(); i++) {
        // if object is set to be destroyed - remove
        CObject* tmp = dynamic_cast<CObject*>( FListObj[i] );
        if( tmp && tmp->isToDestroy() )
            removeObject(i);
        else {
            FListObj[i]->update();
            FListObj[i]->move();
        }
    }
}
