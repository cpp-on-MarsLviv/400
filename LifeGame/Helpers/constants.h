#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <vector>

#include <QString>
#include <QFont>
#include <QTranslator>

using std::vector;

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

// Life area sizes
const vector<size_t> areaSizes = {20, 50, 100, 200, 300};
const int defaultAreaWidth = 20;

// Life area density
const double minDensity = 0.05;
const double densityStep = 0.05;
const double maxDensity = 0.5;
const double defaultDensity = 0.15;

// Cell can die or born other Cell
const float probabilityToDeath = 0.3;
const float probabilityToBorn = 0.3;

// Cell colors in different states
const auto emptyStateColor = Qt::white;
const auto lowSettledStateColor = Qt::cyan;
const auto normSettledStateColor = Qt::green;
const auto hardSettledStateColor = Qt::red;

// Life timing in seconds
const size_t defaultTiming = 1000;
const size_t minTiming = 50;
const size_t maxTiming = 5000;

// Generator seeds
const int seed7 = 7;
const int seed43 = 43;

// Blank Model constants
const QString blankModelMessageInfo = "Creating new Life Area ...";
const auto blankModelColor = Qt::white;
const auto blankModelFont = QFont("Times",50);
}
#endif // CONSTANTS_H
