#include "cspace.h"

CSpace::CSpace() {
    setSceneRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    setBackgroundBrush( QImage( SPACE_BACKGROUND )  );

    QGraphicsPixmapItem* coordinates = new QGraphicsPixmapItem(
                QPixmap::fromImage(
                    QImage( "../graphics/coordinates.png" )
                    )
                );
    coordinates->setPos(0, 0);
    coordinates->setZValue(2);
    addItem(coordinates);
}
