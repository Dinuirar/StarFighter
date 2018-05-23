#include "cautopilot.h"

CAutoPilot::CAutoPilot() { }

CAutoPilot::CAutoPilot(CShip *SHIP, eAiAlgorithm ALGORITHM)
    : ship(SHIP), algorithm(ALGORITHM), counterAi(0)
{
    QTimer* timerEnemy = new QTimer(this);
    connect( timerEnemy, SIGNAL( timeout() ), this, SLOT( updateAi() ) );
    timerEnemy->start(dt);
}

void CAutoPilot::setShip(CShip *SHIP) {
    ship = SHIP;
}

void CAutoPilot::setAlgorithm(eAiAlgorithm ALGORITHM) {
    algorithm = ALGORITHM;
}

void CAutoPilot::updateAi() {
    counterAi++;
    if ( algorithm == SIMPLE ){
        if ( counterAi % 2 && counterAi < 400 ) {
            ship->changeAngularSpeed(0.01);
            ship->changeLinearSpeed(0.01);
        }
        else if ( counterAi % 2 && counterAi > 800 ) {
            ship->changeAngularSpeed(-0.01);
    //        ship->changeLinearSpeed(-0.005);
        }
        if( counterAi % 100 == 0 )
            ship->getType();
        if ( !(counterAi % 100) ) {
            //ship->changeAngularSpeed(-0.01);
            ship->attack();
        }
    }
    else if ( algorithm == ADVANCED ) {
        // to do; use empty attacks to check line of sight!
    }
}
