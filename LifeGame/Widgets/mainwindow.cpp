#include "Helpers/constants.h"
#include "mainwindow.h"

#include <QDebug>

#include <QMenuBar>
#include <QAction>
#include <QWheelEvent>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    qInfo() << "MainWindow started";

    createMenu();

}

MainWindow::~MainWindow()
{
}



void MainWindow::createMenu()
{
    actionsMenu = menuBar()->addMenu(Helpers::menuName);
    actionsMenu->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

    startGame = new QAction(Helpers::actionStart, this);
    connect(startGame, &QAction::triggered, this, &MainWindow::onStartLife);

    stopGame = new QAction(Helpers::actionStop, this);
    stopGame->setDisabled(true);
    connect(stopGame, &QAction::triggered, this, &MainWindow::onStopLife);

    increaseDensity = new QAction(Helpers::actionIncreaseDensity, this);
    connect(increaseDensity, &QAction::triggered, this, &MainWindow::onIncreaseDensity);

    decreaseDensity = new QAction(Helpers::actionDecreaseDensity, this);
    connect(decreaseDensity, &QAction::triggered, this, &MainWindow::onDecreaseDensity);

    actionsMenu->addAction(startGame);
    actionsMenu->addAction(stopGame);
    actionsMenu->addSeparator();
    actionsMenu->addAction(increaseDensity);
    actionsMenu->addAction(decreaseDensity);
}



void MainWindow::onStartLife()
{
    qDebug() << "startTheLife()";
    startGame->setDisabled(true);
    stopGame->setDisabled(false);
    increaseDensity->setDisabled(true);
    decreaseDensity->setDisabled(true);
}

void MainWindow::onStopLife()
{
    qDebug() << "stopTheLife()";
    stopGame->setDisabled(true);
    startGame->setDisabled(false);
    increaseDensity->setDisabled(false);
    decreaseDensity->setDisabled(false);
}

void MainWindow::onIncreaseDensity()
{
    qDebug() << "increaseInitialDensity()";
}

void MainWindow::onDecreaseDensity()
{
    qDebug() << "decreaseInitialDensity()";
}


void MainWindow::wheelEvent(QWheelEvent *event)
{
    QPoint numDegrees = event->angleDelta();
    auto y = numDegrees.ry();
    qDebug() << "numDegrees:" << y;

    event->accept();
}
