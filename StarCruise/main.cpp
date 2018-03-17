//#include "keyhandlers.h"
#include "ship.h"

#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <iostream>

int main(int argc, char *argv[]) {
    QString graphicspath = "../graphics/",
            backgroundname = "alfa-background.png",
            shipname = "alfa-ship.png";
    QApplication a(argc, argv);

    QGraphicsScene* scene = new QGraphicsScene();
    scene->setBackgroundBrush( QImage( graphicspath + backgroundname )  );

    ship* item = new ship( QPixmap::fromImage( QImage ( graphicspath + shipname ) ) );
    item->setScale(0.3);
    item->setFocus();
    scene->addItem(item);

    QGraphicsView view(scene);
    view.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "StarCruise"));
    view.resize(600, 600);
    view.show();

    std::cout << "xd\n";
    return a.exec();
}
