#include "cmenu.h"

CMenu::CMenu() {
    coordinates = new QGraphicsPixmapItem(
                QPixmap::fromImage(
                    QImage(
                        "../graphics/coordinates.png"
                        )
                    )
                );
    coordinates->setPos(0,0);
    this->addItem(coordinates);
}
