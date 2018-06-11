#ifndef GGRAPHICS_H
#define GGRAPHICS_H

#include "cobject.h"
#include <QString>
#include <QGraphicsPixmapItem>

class CObject;

class GGraphics : public QGraphicsPixmapItem {
private:
    CObject* fobject;
    qreal centerW, centerH;
    int start_cnt;
protected:
    int getCounter() { return start_cnt; }
public:
    GGraphics();
    GGraphics( QString, CObject * );
    GGraphics( QString, CObject *, qreal scale );
    void advance( int );
    void setObject( CObject* p_object ) { fobject = p_object; }
    void setModel( QString );
};

#endif // GGRAPHICS_H
