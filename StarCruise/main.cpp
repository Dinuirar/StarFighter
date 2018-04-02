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

// explicit /constructor/; virtual /function/; override /function/; slot:

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QString backgroundname = "background-beta-black.png", //"alfa-background.png",
//            shipname = "ship-raider.png";
//              shipname = "ship-viper2.png";
            shipname = "ship-viper7.png";
    qreal width = windowWidth,
            height = windowHeight;

    CMenu* scene = new CMenu(0., 0., windowWidth, windowHeight);
    scene->setBackgroundBrush( QImage( graphicspath + backgroundname )  );

    CShip* item = new CShip(graphicspath + shipname, PLASMA, 2, 0, 0, 0);
    item->setScale(0.2);
    scene->addItem(item);
    scene->player = item;
    scene->player->map = scene;

    CAsteroid* test_asteroid = new CAsteroid(graphicspath + /*"asteroid2.png"*/ "basic-asteroid.png", 0, 0, 0, 0, 0, .1);
    test_asteroid->setScale(0.2);
    scene->addItem(test_asteroid);

    QGraphicsPixmapItem* coordinates = new QGraphicsPixmapItem( QPixmap::fromImage( QImage( graphicspath+"coordinates.png" ) ) );
    coordinates->setPos(0, 0); coordinates->setZValue(2); scene->addItem(coordinates);

    QGraphicsView view(scene);
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "StarCruise"));
    view.setSceneRect( QRectF(0, 0, width, height) );

    view.show();
    return a.exec();
}
