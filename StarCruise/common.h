#ifndef COMMON_H
#define COMMON_H

#include <QString>

const int dt = 10; // timestep in [ms]
const QString graphicspath = "../graphics/";

const qreal windowWidth = 900.,
          windowHeight = 500.;
const qreal normalAcceleration = 0.1;
const qreal speedMaxAngular = 0.2;
const qreal speedMaxLinearFrwd = 0.3;
const qreal speedMaxLinearBkwd = 0.;
const int laserDelay = 20;
const int plasmaDelay = 40;
const int kineticDelay = 10;
const int laserEnergyCost = 10;
const int plasmaEnergyCost = 20;
const int kineticEnergyCost = 5;
const int laserSpeed = 3;
const int plasmaSpeed = 5;
const int kineticSpeed = 1;

const QString laserName = "laser.png";
const QString plasmaName = "plasma.png";
const QString kineticName = "kinetic.png";

enum eDifficulty { EASY, MEDIUM, HARD };
enum eGameMode { ONE_PLAYER, TWO_PLAYERS };
enum eAiAlgorithm { SIMPLE, ADVANCED };

enum eShipClass { INTERCEPTOR, BERSERK, TANK };
enum eWeaponID { PLASMA, LASER, KINETIC };
enum eLineOfSight { NOTHING, SHIP, ASTEROID };

#endif // COMMON_H
