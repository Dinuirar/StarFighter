#ifndef CMENU_H
#define CMENU_H

#include "common.h"
#include "cship.h"
#include <QGraphicsScene>
#include <QTimer>
#include <iostream>

#include "common.h"

class CMenu : public QGraphicsScene {
    Q_OBJECT
public:
    CMenu();
    CMenu(qreal X, qreal Y, qreal WIDTH, qreal HEIGHT);
    bool startNewGame();
    bool displayInstruction();
    void setGameMode(eGameMode MODE);
    void setDifficulty(eDifficulty DIFF);
    void setAiAlgorithm(eAiAlgorithm ALGORITHM);
    int getCounter() { return counter; }
    void keyPressEvent(QKeyEvent *event);
    CShip * player;
public slots:
    virtual void update();
protected:
    int counter;
    eDifficulty level;
    eGameMode mode;
    eAiAlgorithm ai;
    QString instructionFileName;
    QGraphicsSimpleTextItem* title;
};

#endif // CMENU_H
