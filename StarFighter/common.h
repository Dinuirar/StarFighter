#ifndef COMMON_H
#define COMMON_H

#include <QString>

extern int WINDOW_WIDTH;
extern int WINDOW_HEIGHT;
extern QString SPACE_BACKGROUND;
extern const QString laserName;
extern const QString plasmaName;
extern const QString kineticName;
extern qreal dt;
extern int MAX_LIN_SPEED_SQR;
extern int MAX_ANG_SPEED;
extern qreal SHIPSCALE;
extern int HOWMANYASTEROIDS;

const QString asteroids[] = { "asteroid1.png", "asteroid2.png", "asteroid3.png", "asteroid4.png" };


enum EWeaponID { PLASMA, LASER, KINETIC };

enum EDifficulty { EASY, MEDIUM, HARD };

enum EId { PLAYER, NPC };

qreal deg2rad( qreal deg );
qreal rad2deg( qreal rad );

class CSettings {
public:
    EDifficulty FDifficulty;
    // typ statku, typ uzbrojenia
};

#endif // COMMON_H
