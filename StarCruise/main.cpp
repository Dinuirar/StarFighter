#include "common.h"
#include "cship.h"
#include "casteroid.h"
#include "cmenu.h"
#include "cweapons.h"
#include "cautopilot.h"

#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <iostream>

// explicit /constructor/; virtual /function/; override /function/; slot:

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QString backgroundname = "background-beta-black.png", //"alfa-background.png",
            name_enemy = "ship-raider.png",
//              shipname = "ship-viper2.png";
            shipname = "ship-viper7.png";
    qreal width = windowWidth,
            height = windowHeight;

    CMenu* scene = new CMenu(0., 0., windowWidth, windowHeight);
    scene->setBackgroundBrush( QImage( graphicspath + backgroundname )  );

    CShip* enemy = new CShip(graphicspath + name_enemy, LASER, 0, 100, 100, 30);
    enemy->setScale(0.2);
    scene->addItem(enemy);
    scene->player = enemy;
    scene->player->map = scene;

    CAutoPilot * enemy_pilot = new CAutoPilot(enemy);

    CShip* player = new CShip(graphicspath + shipname, PLASMA, 2, 0, 0, 0);
    player->setScale(0.2);
    scene->addItem(player);
    scene->player = player;
    scene->player->map = scene;

    CAsteroid* test_asteroid = new CAsteroid(graphicspath +
                                             //"basic-asteroid.png",
                                             "game-references/asteroid2.png",
                                             0, 0, 0, 0, 0, .1);
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
