#ifndef MOVESHIP_H
#define MOVESHIP_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>

class ship : public QGraphicsPixmapItem {
public:
    ship();
    explicit ship(const QPixmap pixitem);
    void keyPressEvent(QKeyEvent *event);
//protected:
private:
    qreal a;
    qreal b;
    qreal ang;
};

#endif // MOVESHIP_H
