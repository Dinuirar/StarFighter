#include <QString>

int WINDOW_WIDTH = 800;
int WINDOW_HEIGHT = 500;
QString SPACE_BACKGROUND = "../graphics/background-beta-black.png";
const QString laserName = "laser.png";
const QString plasmaName = "plasma.png";
const QString kineticName = "kinetic.png";
qreal dt = 0.1;
qreal SHIPSCALE = 0.2;
int HOWMANYASTEROIDS = 3;

int MAX_LIN_SPEED_SQR = 8000;
int MAX_ANG_SPEED = 8;

qreal deg2rad( qreal deg ) {
    return deg * 0.01744;
}

qreal rad2deg( qreal rad ) {
    return rad * 57.32;
}
