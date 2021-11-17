#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <QString>
#include <QTranslator>

namespace Helpers {

// application
const QString appName = "Game Life v 0.1    IN DEVELOPMENT";
const int appWidthDefault = 1300;
const int appHeightDefault = 800;
const QString appLogfileDefault = "./LifeGame.log";

// Menu names
const QString menuName = "&Controls";
const QString actionStart = "&Start Life";
const QString actionStop = "S&top Life";
const QString actionIncreaseDensity = "&Increase Density";
const QString actionDecreaseDensity = "&Decrease Density";

// Life area size
const int minAreaWidth = 100;
const int maxAreaWidth = 300;
const int defaultAreaWidth = 200;
const int debugAreaWidth20 = 20;
}
#endif // CONSTANTS_H
