#ifndef CMENU_H
#define CMENU_H

#include "common.h"
#include "ship.h"
#include <QGraphicsScene>
#include <QTimer>
#include <iostream>

class CMenu : public QGraphicsScene {
    Q_OBJECT
public:
    CMenu();
    CMenu(qreal X, qreal Y, qreal WIDTH, qreal HEIGHT);
    bool startNewGame();
    bool displayInstruction();
    void setGameMode();
    void setDifficulty();
    void setAiAlgorithm();
    void keyPressEvent(QKeyEvent *event);
    CShip * player;
    int getCounter() { return counter; }
public slots:
    virtual void update();
protected:
    int counter;
    difficulty level;
    gameMode mode;
    aiAlgorithm ai;
    QString instructionFileName;
    QGraphicsSimpleTextItem* title;
};

#endif // CMENU_H
