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

    hp_indicator = new QGraphicsSimpleTextItem();
    hp_indicator->setZValue(3);
    hp_indicator->setFont( QFont("Helvetica", 17) );
    hp_indicator->setBrush( QColor(0, 0, 255, 127) );
    hp_indicator->setPos( 80, 10 );
    this->addItem( hp_indicator );

    enemy_hp_indicator = new QGraphicsSimpleTextItem();
    enemy_hp_indicator->setZValue(3);
    enemy_hp_indicator->setFont( QFont("Helvetica", 17) );
    enemy_hp_indicator->setBrush( QColor(255, 0, 0, 127) );
    enemy_hp_indicator->setPos( 380, 10 );
    this->addItem( enemy_hp_indicator );
}

std::deque<CObject*> CSpace::getObjInRange(CObject *_obj, qreal _range) {
    std::deque<CObject*> objInRange;
    for (u_int i = 0; i < FListObj.size(); i++) {
        if( dynamic_cast<CBullet*>(FListObj[i]) != NULL )
            continue;
        if( _obj->calcDistance(FListObj[i]) <= _range )
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
    if ( !enemy ) {
        CShip* tmp = dynamic_cast<CShip*>( _obj );
        if( !tmp ) return;
        if( tmp->getID() == NPC )
            enemy = tmp;
    }
}

void CSpace::removeObject( u_int index ) {
    QGraphicsItem* _item = this->itemAt( FListObj[index]->getPosition(), QTransform() );
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
    delete FListGraphics[index];
    FListObj.erase(_iposition);
    FListGraphics.erase(__iposition);
}

void CSpace::updateObjs() {
    if( player ) {
        playerHP = QString::number( player->getHP() );
        hp_indicator->setText( "player: " + playerHP );
    }
    else {
        hp_indicator->setText( "you won!" );
    }


    if ( enemy ) {
        enemyHP = QString::number( enemy->getHP() );
        enemy_hp_indicator->setText( "enemy: " + enemyHP );
    }
    else {
        enemy_hp_indicator->setText( "you won!" );
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
