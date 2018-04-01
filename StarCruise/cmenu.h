#ifndef CMENU_H
#define CMENU_H

#include "common.h"
#include "ship.h"
#include <QGraphicsScene>
#include <QTimer>
#include <iostream>

class CMenu : public QGraphicsScene {
public:
    CMenu();
    CShip * player;
    int counter;
    bool startNewGame();
    bool displayInstruction();
    void setGameMode();
    void setDifficulty();
    void setAiAlgorithm();
    void update();
    void timerEvent(QTimerEvent *);
    void keyPressEvent(QKeyEvent *event);
private:
    difficulty level;
    gameMode mode;
    aiAlgorithm ai;
    QString instructionFileName;
};

#endif // CMENU_H
