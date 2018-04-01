#include "ship.h"
#include "cmenu.h"
#include <QList>

CMenu::CMenu() : counter(0) { }

void CMenu::timerEvent(QTimerEvent *) {
//    QList<QGraphicsItem*> tmp = this->items();
//    if( counter%2 )
//        tmp.at(1)->setFocus();
//    else
//        tmp.at(2)->setFocus();
    counter++;
//    std::cout << counter%2 << "\n";
}

void CMenu::keyPressEvent(QKeyEvent *event) {
    qreal def_delta = 0.007;
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
    }
}
