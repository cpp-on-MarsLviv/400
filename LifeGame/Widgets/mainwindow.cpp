#include "Helpers/constants.h"
#include "mainwindow.h"

#include <QDebug>

#include <QMenuBar>
#include <QAction>
#include <QWheelEvent>

#include <QTextTableFormat>
#include <QHBoxLayout>
#include <QTableView>
#include <QHeaderView>

using std::make_shared;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    qInfo() << "MainWindow started";

    createMenu();
    createUI();
}

MainWindow::~MainWindow()
{
}



void MainWindow::createMenu()
{
    actionIncreaseDensityLimited = false;
    actionDecreaseDensityLimited = true;

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
    decreaseDensity->setDisabled(true);
    connect(decreaseDensity, &QAction::triggered, this, &MainWindow::onDecreaseDensity);

    actionsMenu->addAction(startGame);
    actionsMenu->addAction(stopGame);
    actionsMenu->addSeparator();
    actionsMenu->addAction(increaseDensity);
    actionsMenu->addAction(decreaseDensity);


}

void MainWindow::createUI() {
    modelParams = make_shared<ModelParams>(ModelParams(Helpers::defaultAreaWidth,
                                                       Helpers::defaultTiming,
                                                       Helpers::defaultDensity,
                                                       Helpers::probabilityToBorn,
                                                       Helpers::probabilityToDeath));
    blankModel = new BlankModel(this);
    lifeModel = new LifeModel(modelParams, this);

    tableView = new QTableView;

    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    tableView->horizontalHeader()->setMaximumSectionSize(0);
    tableView->verticalHeader()->setMaximumSectionSize(0);

    tableView->horizontalHeader()->hide();
    tableView->verticalHeader()->hide();

    tableView->setModel(lifeModel);

    setCentralWidget(tableView);
}

void MainWindow::onStartLife()
{
    qDebug() << "startTheLife()";
    startGame->setDisabled(true);
    stopGame->setDisabled(false);

    increaseDensity->setDisabled(true);
    decreaseDensity->setDisabled(true);

    dynamic_cast<LifeModel*>(lifeModel)->startLife(modelParams->getTiming());
}

void MainWindow::onStopLife()
{
    qDebug() << "stopTheLife()";
    stopGame->setDisabled(true);
    startGame->setEnabled(true);
    if (!actionIncreaseDensityLimited)
        increaseDensity->setEnabled(true);
    if (!actionDecreaseDensityLimited)
        decreaseDensity->setEnabled(true);

}

void MainWindow::onIncreaseDensity()
{
    qDebug() << "increaseInitialDensity()";
    actionDecreaseDensityLimited = false;

    startGame->setDisabled(true);
    increaseDensity->setDisabled(true);
    decreaseDensity->setDisabled(true);

    size_t currentWidth = modelParams->getAreaWidth();
    auto iteratorToCurrentWidth = std::find(Helpers::areaSizes.begin(), Helpers::areaSizes.end(), currentWidth);
    size_t indexOfCurrentWidth = iteratorToCurrentWidth - Helpers::areaSizes.begin();
    qDebug () << "indexOfCurrentWidth:" << indexOfCurrentWidth;
    size_t indexOfRequestedWidth = ++indexOfCurrentWidth;
    if (indexOfRequestedWidth == Helpers::areaSizes.size() - 1)
        actionIncreaseDensityLimited = true;

    tableView->setModel(blankModel);
    auto currentFont = tableView->font();
    tableView->setFont(Helpers::blankModelFont);

    modelParams = make_shared<ModelParams>(ModelParams(Helpers::areaSizes[indexOfRequestedWidth],
                                                       Helpers::defaultTiming,
                                                       Helpers::defaultDensity,
                                                       Helpers::probabilityToBorn,
                                                       Helpers::probabilityToDeath));
    delete lifeModel;
    lifeModel = new LifeModel(modelParams, this);
    tableView->setModel(lifeModel);
    tableView->setFont(currentFont);

    if (!actionIncreaseDensityLimited)
        increaseDensity->setEnabled(true);

    startGame->setEnabled(true);
    decreaseDensity->setEnabled(true);
}

void MainWindow::onDecreaseDensity()
{
    qDebug() << "decreaseInitialDensity()";

    actionIncreaseDensityLimited = false;

    startGame->setDisabled(true);
    increaseDensity->setDisabled(true);
    decreaseDensity->setDisabled(true);

    size_t currentWidth = modelParams->getAreaWidth();
    auto iteratorToCurrentWidth = std::find(Helpers::areaSizes.begin(), Helpers::areaSizes.end(), currentWidth);
    size_t indexOfCurrentWidth = iteratorToCurrentWidth - Helpers::areaSizes.begin();
    qDebug () << "indexOfCurrentWidth:" << indexOfCurrentWidth;
    size_t indexOfRequestedWidth = --indexOfCurrentWidth;
    if (indexOfRequestedWidth == 0)
        actionDecreaseDensityLimited = true;

    tableView->setModel(blankModel);
    auto currentFont = tableView->font();
    tableView->setFont(Helpers::blankModelFont);

    modelParams = make_shared<ModelParams>(ModelParams(Helpers::areaSizes[indexOfRequestedWidth],
                                                       Helpers::defaultTiming,
                                                       Helpers::defaultDensity,
                                                       Helpers::probabilityToBorn,
                                                       Helpers::probabilityToDeath));
    delete lifeModel;
    lifeModel = new LifeModel(modelParams, this);
    tableView->setModel(lifeModel);
    tableView->setFont(currentFont);

    if (!actionDecreaseDensityLimited)
        decreaseDensity->setEnabled(true);

    startGame->setEnabled(true);
    increaseDensity->setEnabled(true);
}


void MainWindow::wheelEvent(QWheelEvent *event)
{
    if (startGame->isEnabled())
        return;

    QPoint numDegrees = event->angleDelta();
    auto delta = numDegrees.ry();

    size_t currentTiming = modelParams->getTiming();
    if (currentTiming == Helpers::maxTiming && !std::signbit(delta))
        return;
    if (currentTiming == Helpers::minTiming && std::signbit(delta))
        return;

    int requestedTiming = currentTiming + delta;
    if (requestedTiming > static_cast<int>(Helpers::maxTiming))
        requestedTiming = Helpers::maxTiming;
    if (requestedTiming < static_cast<int>(Helpers::minTiming))
        requestedTiming = Helpers::minTiming;
    modelParams->setTiming(requestedTiming);
    qDebug() << "delta:" << delta << "  currentTiming:" << currentTiming << "  requestedTiming:" << requestedTiming;
    dynamic_cast<LifeModel*>(lifeModel)->changeLifeRate(requestedTiming);

    event->accept();
}
