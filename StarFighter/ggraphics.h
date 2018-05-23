#ifndef GGRAPHICS_H
#define GGRAPHICS_H

#include "cobject.h"
#include <QString>
#include <QGraphicsPixmapItem>

class GGraphics : public QGraphicsPixmapItem {
private:
    CObject* fobject;
    qreal centerW, centerH;
public:
    GGraphics();
    GGraphics( QString, CObject * );
    void advance( int );
    void setObject( CObject* p_object ) { fobject = p_object; }
    void setModel( QString );
};

#endif // GGRAPHICS_H
