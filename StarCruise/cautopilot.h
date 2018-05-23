#ifndef CAUTOPILOT_H
#define CAUTOPILOT_H

#include "cship.h"
#include "common.h"
#include <QTimer>

class CAutoPilot : public QObject {
    Q_OBJECT
public:
    CAutoPilot();
    CAutoPilot(CShip * SHIP, eAiAlgorithm ALGORITHM = SIMPLE);
    void setShip(CShip * SHIP);
    void setAlgorithm(eAiAlgorithm ALGORITHM);
public slots:
    void updateAi();
//protected:
private:
    CShip * ship;
    eDifficulty level;
    eAiAlgorithm algorithm;
    int counterAi;
};

#endif // CAUTOPILOT_H
