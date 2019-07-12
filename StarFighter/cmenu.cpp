#include "cmenu.h"

CMenu::CMenu() {
    this->setSceneRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    this->setBackgroundBrush( QImage( SPACE_BACKGROUND )  );
}

CMenu::CMenu( CSettings* settings )
    : Fsettings(settings) {
    this->setSceneRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    this->setBackgroundBrush( QImage( SPACE_BACKGROUND )  );

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

