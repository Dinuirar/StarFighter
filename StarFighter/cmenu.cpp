#include "cmenu.h"

CMenu::CMenu() {
    coordinates = new QGraphicsPixmapItem(
                QPixmap::fromImage(
                    QImage(
                        "/home/kassus/Desktop/Qt/github/StarCruise/graphics/coordinates.png"
                        )
                    )
                );
    coordinates->setPos(0,0);
    this->addItem(coordinates);
}
