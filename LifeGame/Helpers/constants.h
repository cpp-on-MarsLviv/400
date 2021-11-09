#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <QString>
#include <QTranslator>

namespace Helpers {

// application
const QString appName = "Game Life v 0.1";
const int appWidthDefault = 1300;
const int appHeightDefault = 800;
const QString appLogfileDefault = "./LifeGame.log";

// Menu names
const QString menuName = "&Controls";
const QString actionStart = "&Start Life";
const QString actionStop = "S&top Life";
const QString actionIncreaseDensity = "&Increase Density";
const QString actionDecreaseDensity = "&Decrease Density";
/*
const int layoutProportions[] = {2, 5, 5};


// Input Image Title
const QString titleInputImage = QObject::tr("INPUT IMAGE");
const QString styleInputImageTitle = "QLabel {    background-color : grey; padding: 6px; "
                                    " font : Times New Roman;  font-size: 24px; font-style: italic;"
                                    " color : blue; border-radius : 10px; border-style : outset; border-width : 2px; border-color : beige; }";
const QFlags<Qt::AlignmentFlag> alignmentInputImageTitle = Qt::AlignCenter;

// Dropdown Menu
const QString titleDropdownMenuLabel = QObject::tr("Select Conversion");
const QString styleDropdownMenuLabel = "QLabel { background-color : grey; font : Times New Roman; font-size: 24px; color : black;  }";
const QString styleDropdownMenuList = "QComboBox {    background-color : grey; "
                                    " font : Times New Roman;  font-size: 24px; "
                                    " color : black;  }";


// Convert Button
const QString titleConvertButton = QObject::tr("Convert");
const QString styleConvertButton = "QPushButton {    background-color : grey; "
                                    " font : Times New Roman;  font-size: 20px; "
                                    " color : black;  }";

// Output Image Title
const QString titleOutputImage = QObject::tr("OUTPUT IMAGE");
const QString styleOutputImageTitle = "QLabel {    background-color : grey; padding: 6px; "
                                    " font : Times New Roman;  font-size: 24px; font-style: italic;"
                                    " color : blue; border-radius : 10px; border-style : outset; border-width : 2px; border-color : beige; }";
const QFlags<Qt::AlignmentFlag> alignmentOutputImageTitle = Qt::AlignCenter;

// Save button
const QString titleSaveButton = QObject::tr("Save ...");
const QString styleSaveButton = "QPushButton {    background-color : grey; "
                                    " font : Times New Roman;  font-size: 16px; "
                                    " color : black;  }";

// Exit button
const QString titleExitButton = QObject::tr("Exit");
const QString styleExitButton = "QPushButton {    background-color : grey; "
                                    " font : Times New Roman;  font-size: 20px; "
                                    " color : black;  }";

// Error message
const QString titleErrorMessage = QObject::tr("Can't load %1: %2");
*/
}
#endif // CONSTANTS_H
