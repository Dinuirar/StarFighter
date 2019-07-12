#include <QString>
#include "common.h"

const QString graphics_dir = "../graphics/";
const QString ship_graphics = graphics_dir + "basic_ship.png";
const QString SPACE_BACKGROUND = graphics_dir + "background-beta-black.png";
const QString laserName = "laser.png";
const QString plasmaName = "plasma.png";
const QString kineticName = "kinetic.png";

u_int WINDOW_WIDTH = 800;
u_int WINDOW_HEIGHT = 600;

QString destroyedMessage = "n/a";
qreal dt = 0.1;
qreal SHIPSCALE = 0.8;
u_int HOWMANYASTEROIDS = 5;
u_int laser_energy_cost = 10;
u_int plasma_energy_cost = 8;
u_int kinetic_energy_cost = 3;

qreal deg2rad( qreal deg ) {
    return deg * 0.01744;
}

qreal rad2deg( qreal rad ) {
    return rad * 57.32;
}

int signed_rand() {
   return (rand() - RAND_MAX/2);
}
