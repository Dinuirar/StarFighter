#include "cmenu.h"
#include <QList>
#include <QGraphicsItem>
#include "ship.h"

void CMenu::update() {
    std::cout << "jakies spc czy pjc\n";
}

CMenu::CMenu()
    : counter(0) {
    std::cout << "?\n";
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT( update() ));
    timer->start(1000);
    std::cout << "??\n";
}

void CMenu::timerEvent(QTimerEvent *) {
    QList<QGraphicsItem*> tmp = this->items();
    if( counter%2 )
        tmp.at(1)->setFocus();
    else
        tmp.at(2)->setFocus();
    counter++;
//    std::cout << counter%2 << "\n";
}
