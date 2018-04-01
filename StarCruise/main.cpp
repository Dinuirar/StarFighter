#include "common.h"
#include "ship.h"
#include "asteroid.h"
#include "cmenu.h"
#include "cweapons.h"

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
    QString backgroundname = "background-beta-black.png", //"alfa-background.png",
//            shipname = "ship-raider.png";
              shipname = "ship-viper2.png";
//            shipname = "ship-viper7.png";
    QApplication a(argc, argv);

    CMenu* scene = new CMenu();
    scene->setBackgroundBrush( QImage( graphicspath + backgroundname )  );

    CShip* item = new CShip(graphicspath + shipname, LASER, 1, 0, 0, 0);
    item->setScale(0.2);
    scene->addItem(item);
    scene->player = item;
    scene->player->map = scene;

    CAsteroid* test_asteroid = new CAsteroid(graphicspath + "basic-asteroid.png", 0, 0, 0, 0, .1, .1);
    test_asteroid->setScale(0.2);
    scene->addItem(test_asteroid);

    QGraphicsView view(scene);
    view.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "StarCruise"));
    view.resize(650, 650);
    view.show();
    return a.exec();
}
