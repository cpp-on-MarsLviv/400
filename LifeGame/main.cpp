#include "Widgets/mainwindow.h"

#include "Utils/applocation.h"
#include "Helpers/constants.h"

#include "Utils/logger.h"

#include <QApplication>
#include <QScreen>

int main(int argc, char *argv[])
{
    Logger::init();
    qInfo() << "main started";

    QApplication a(argc, argv);
    MainWindow mainWindow;

    Utils::AppLocation::calculateAppGeometry();
    mainWindow.move(Utils::AppLocation::appMoveOnX, Utils::AppLocation::appMoveOnY);       // move App to screen center
    mainWindow.setMinimumWidth(Utils::AppLocation::appMinWidth);
    mainWindow.setMinimumHeight(Utils::AppLocation::appMinHeight);

    mainWindow.setWindowTitle(Helpers::appName);
    mainWindow.show();

    //Logger::clean();

    return a.exec();
}






