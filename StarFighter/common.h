#ifndef COMMON_H
#define COMMON_H

#include <QString>
#include <cmath>

typedef uint u_int;

extern u_int WINDOW_WIDTH;
extern u_int WINDOW_HEIGHT;
extern const QString graphics_dir;
extern const QString ship_graphics;
extern const QString SPACE_BACKGROUND;
extern const QString laserName;
extern const QString plasmaName;
extern const QString kineticName;
extern qreal dt;
extern qreal SHIPSCALE;
extern u_int HOWMANYASTEROIDS;
extern QString destroyedMessage;
const QString asteroids[] = { "asteroid1.png", "asteroid2.png", "asteroid3.png", "asteroid4.png" };
extern u_int laser_energy_cost;
extern u_int plasma_energy_cost;
extern u_int kinetic_energy_cost;

enum EWeaponID { PLASMA, LASER, KINETIC };
enum EDifficulty { EASY, MEDIUM, HARD };
enum EId { PLAYER, NPC };

qreal deg2rad( qreal deg );
qreal rad2deg( qreal rad );
int signed_rand();

class CSettings {
public:
    EDifficulty FDifficulty;
    // ship's type, weapon's type
    EWeaponID player_weapon, enemy_weapon;
};

#endif // COMMON_H
