#include "ship.h"
#include "cmenu.h"
#include <QList>

CMenu::CMenu() : counter(0) { }

CMenu::CMenu(qreal X, qreal Y, qreal WIDTH, qreal HEIGHT)
    : QGraphicsScene(X, Y, WIDTH, HEIGHT), counter(0) {
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT( update() ));
    timer->start(dt);
    title = new QGraphicsSimpleTextItem( "StarFighter The PJC Game" );
    this->addItem(title);
}

void CMenu::keyPressEvent(QKeyEvent *event) {
    qreal def_delta = normalAcceleration;
    if( player->id == 1 ) {
        if( event->key() == Qt::Key_S ) {
            player->changeLinearSpeed( -def_delta );
        }
        if( event->key() == Qt::Key_W ) {
            player->changeLinearSpeed( def_delta );
        }
        if( event->key() == Qt::Key_D ) {
            player->changeAngularSpeed( def_delta );
        }
        if( event->key() == Qt::Key_A ) {
            player->changeAngularSpeed( -def_delta );
        }
        if( event->key() == Qt::Key_Space ) {
            player->attack();
        }
    }

    if (player->id == 2){
        if( event->key() == Qt::Key_Down ) {
            player->changeLinearSpeed( -def_delta );
        }
        if( event->key() == Qt::Key_Up ) {
            player->changeLinearSpeed( def_delta );
        }
        if( event->key() == Qt::Key_Right ) {
            player->changeAngularSpeed( def_delta );
        }
        if( event->key() == Qt::Key_Left ) {
            player->changeAngularSpeed( -def_delta );
        }
        if( event->key() == Qt::Key_Shift ) {
            player->attack();
        }
    }
}

void CMenu::update() {
    counter++;
    this->removeItem(title);
    delete title;
    QString number = QString::number(counter);
    title = new QGraphicsSimpleTextItem( "StarFighter The PJC Game " + number );
    title->setZValue(2);
    title->setFont( QFont("Helvetica", 17) );
    title->setBrush( QColor(255, 0, 0, 127) );
    title->setPos( 80., 10. );
    this->addItem(title);
}
