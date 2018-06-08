#include <QString>

u_int WINDOW_WIDTH = 800;
u_int WINDOW_HEIGHT = 500;
QString SPACE_BACKGROUND = "../graphics/background-beta-black.png";
const QString laserName = "laser.png";
const QString plasmaName = "plasma.png";
const QString kineticName = "kinetic.png";
qreal dt = 0.1;
qreal SHIPSCALE = 0.2;
u_int HOWMANYASTEROIDS = 5;
QString destroyedMessage = "n/a";
u_int laser_energy_cost = 10;
u_int plasma_energy_cost = 8;
u_int kinetic_energy_cost = 3;

//int MAX_LIN_SPEED_SQR = 8000;
//int MAX_ANG_SPEED = 8;

qreal deg2rad( qreal deg ) {
    return deg * 0.01744;
}

qreal rad2deg( qreal rad ) {
    return rad * 57.32;
}
