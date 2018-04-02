#ifndef CWEAPONS_H
#define CWEAPONS_H

#include "cinertion.h"
#include "common.h"

/////////////////////////////////////////////////////////////
class CWeapons : public CInertion {
private:
    QString modelName;
    int EnergyCost;
    int Delay;
public:
    CWeapons();
    CWeapons(QString MODELNAME, int ENERGYCOST, int DELAY,
             qreal X, qreal Y, qreal ANGLE,
             qreal LINEAR_SPEED = -1);
    int energyCost() { return EnergyCost; }
    int delay() {return Delay; }
};

/////////////////////////////////////////////////////////////
class CPlasma : public CWeapons {
public:
    CPlasma();
    CPlasma( qreal X, qreal Y, qreal ANGLE,
             qreal LINEAR_SPEED = -plasmaSpeed);
private:
    QString modelName;
};

/////////////////////////////////////////////////////////////
class CLaser : public CWeapons {
public:
    CLaser();
    CLaser( qreal X, qreal Y, qreal ANGLE,
            qreal LINEAR_SPEED = -laserSpeed);
private:
    QString modelName;
};

/////////////////////////////////////////////////////////////
class CKinetic : public CWeapons {
public:
    CKinetic();
    CKinetic( qreal X, qreal Y, qreal ANGLE,
              qreal LINEAR_SPEED = -kineticSpeed);
private:
    QString modelName;
};

/////////////////////////////////////////////////////////////
#endif // CWEAPONS_H
