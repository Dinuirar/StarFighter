#include "ship.h"
#include "asteroid.h"
#include "cmenu.h"

#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <iostream>

// explicit /constructor/
// virtual /function/
// override /function/
// slot:
//

int main(int argc, char *argv[]) {
    QString graphicspath = "../graphics/",
            backgroundname = "background-beta-black.png", //"alfa-background.png",
            shipname = "alfa-ship-red.png",
            shipname2 = "alfa-ship-pink.png";
    QApplication a(argc, argv);

    CMenu* scene = new CMenu();
    scene->startTimer(10);
    scene->setBackgroundBrush( QImage( graphicspath + backgroundname )  );

    ship* item = new ship(graphicspath + shipname, 1, 0, 0, 0);
    item->setScale(0.3);
    item->setPos(60, 30);
    item->setOffset(1, 1);
    scene->addItem(item);

    ship* item2 = new ship(graphicspath + shipname2, 2, 0, 0, 0);
    item2->setScale(0.2);
    scene->addItem(item2);

    scene->setFocus();

    Asteroid* test_asteroid = new Asteroid(graphicspath + "basic-asteroid.png", 0, 0, 0, 0, .1, .1);
    test_asteroid->setScale(1);
    scene->addItem(test_asteroid);

    QGraphicsView view(scene);
    view.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "StarCruise"));
    view.resize(650, 650);
    view.show();

    return a.exec();
}
