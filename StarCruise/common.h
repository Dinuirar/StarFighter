#ifndef COMMON_H
#define COMMON_H

#include <QString>

const int dt = 1; // timestep in [ms]
const QString graphicspath = "../graphics/";

const int laserEnergyCost = 10;
const int plasmaEnergyCost = 20;
const int kineticEnergyCost = 5;
const int laserSpeed = 3;
const int plasmaSpeed = 5;
const int kineticSpeed = 1;
const QString laserName = "laser.png";
const QString plasmaName = "plasma.png";
const QString kineticName = "kinetic.png";

enum difficulty { EASY, MEDIUM, HARD };
enum gameMode { ONE_PLAYER, TWO_PLAYERS };
enum aiAlgorithm { SIMPLE, ADVANCED };

enum shipClass { INTERCEPTOR, BERSERK, TANK };
enum weaponID { PLASMA, LASER, KINETIC };
enum lineOfSight { NOTHING, SHIP, ASTEROID };

#endif // COMMON_H
