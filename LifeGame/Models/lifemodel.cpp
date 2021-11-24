#include "lifemodel.h"
#include "cellarea.h"
#include "cell.h"
#include "Helpers/functions.h"
#include "Helpers/generators.h"
#include "Helpers/constants.h"

#include <QBrush>
#include <QTimer>
#include <QTime>

#include <iostream>

using std::for_each;
using std::remove;
using std::cout;
using std::endl;

LifeModel::LifeModel(shared_ptr<ModelParams> newModelParams, QObject *parent) :
    QAbstractTableModel{parent},
    modelParams{newModelParams},
    lifeTimer{new QTimer(this)},
    clockTimer{new QTimer(this)} {
    lifeArea = CellArea::getSharedCells(modelParams->getAreaWidth());
    qDebug() << "made area with size:" << lifeArea->size();
    CellArea::connectCells();
//    for_each(lifeArea->cbegin(), lifeArea->cend(), [idx = 0](shared_ptr<Cell> cell) mutable {
//        qDebug() << "i:" << idx++ << "  :" << cell->neighborsCount(); });
//    for_each(lifeArea->cbegin(), lifeArea->cend(), [idx = 0](shared_ptr<Cell> cell) mutable {
//        qDebug() << "i:" << idx++ << "  state:" << Helpers::to_underlying(cell->getState()); });  // -> 0

    populatedCells = CellArea::seedCells(modelParams->getDensity());

//    if (QBrush(Qt::red) == QBrush(stateColorMapping.at(Cell::State::HARD_SETTLED)))
//        qDebug() << "+++";
    //    else qDebug() << "---";
    cout << "timing:" << modelParams->getTiming() << endl;
    lifeTimer->setInterval(modelParams->getTiming());
    connect(lifeTimer, &QTimer::timeout, this, &LifeModel::makeIteration);

    clockTimer->setInterval(1000);
    connect(clockTimer, &QTimer::timeout , this, &LifeModel::timerHit);
    clockTimer->start();
}

int LifeModel::rowCount(const QModelIndex & /*parent*/) const { return modelParams->getAreaWidth(); }

int LifeModel::columnCount(const QModelIndex & /*parent*/) const { return modelParams->getAreaWidth(); }

QVariant LifeModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int col = index.column();

    if (role == Qt::DisplayRole && row == 0 && col == 0)
        return QTime::currentTime().toString();

    switch (role) {
    case Qt::DisplayRole:
//        return QString("Row%1, Column%2")
//                    .arg(index.row() + 1)
//                    .arg(index.column() + 1);
        return QString("");

    case Qt::BackgroundRole:
        size_t idx = row * modelParams->getAreaWidth() + col; if (idx > 399) {std::cout << "b1: idx:" << idx << "\n" << std::flush;}
        Cell::State state = lifeArea->at(idx)->getState();
        auto color = stateColorMapping.at(state);
        //qDebug() << "idx:" << idx << ", state:" << Helpers::to_underlying(state) << ", color:" << color;
        return QBrush(color);
        //break;
        //return QBrush(stateColorMapping.at(lifeArea->at(row * modelParams->getAreaWidth() + col)->getState()));//lifeArea->at(4)->getState();
//            if (row == 1 && col == 2)
//                return QBrush(Qt::red);
//            break;
    }

    return QVariant();
}
// shared_ptr<vector<shared_ptr<Cell>>> lifeArea;
Qt::ItemFlags LifeModel::flags(const QModelIndex &/*index*/) const { return Qt::NoItemFlags; }

const map<Cell::State, QBrush> LifeModel::stateColorMapping = LifeModel::createStateColorMapping();

map<Cell::State, QBrush> LifeModel::createStateColorMapping()
{
    map<Cell::State, QBrush> mapping;
    mapping[Cell::State::EMPTY] = Helpers::emptyStateColor;
    mapping[Cell::State::LOW_SETTLED] = Helpers::lowSettledStateColor;
    mapping[Cell::State::NORM_SETTLED] = Helpers::normSettledStateColor;
    mapping[Cell::State::HARD_SETTLED] = Helpers::hardSettledStateColor;
    return mapping;
}

void LifeModel::startLife(size_t interval)
{
    cout << "startLife()" << endl;

    lifeTimer->start();
}

void LifeModel::stopLife()
{
    lifeTimer->stop();
    //lifeTimer->deleteLater();
}

void LifeModel::changeLifeRate(int newTiming)
{
    auto currentTiming = lifeTimer->interval();
    qDebug() << "current timing" << currentTiming << "  newTiming" << newTiming;
    lifeTimer->setInterval(newTiming);
}

void LifeModel::makeIteration()
{
    cout << "in makeIter" << endl;
    cout << " There is " << populatedCells->size() << " populated Cells.\n" << std::flush;
    if (populatedCells->size() < 14) {
        for_each(populatedCells->cbegin(), populatedCells->cend(), [lifeArea = lifeArea](const int cell){
            cout << "cell#" << cell << " has:" << lifeArea->at(cell)->neighborsCount() << " neighbors;  ";
        });
        cout << endl;
    }
    std::copy(populatedCells->cbegin(), populatedCells->cend(), std::ostream_iterator<int>(std::cout, " "));
    qDebug() << " There is " << populatedCells->size() << " populated Cells.";
    for_each(populatedCells->begin(), populatedCells->end(), [=, this] (int cellN) {if (cellN > 399) {std::cout << "b2: cellN:" << cellN << "\n" << std::flush;}
        if (lifeArea->at(cellN)->neighborsCount() > Cell::deathLevel && lifeArea->at(cellN)->neighborsCount() <= Cell::normLevel)
            //born Cell - make some non-populated neighbor cell as populated
            int randomNumber = Helpers::Generators::getRandomDeviceNumber(0, 100);
    });

    vector<int> cellsToErase;
    auto& localLifeArea = lifeArea;
    auto& localPopulatedCells = populatedCells;
    auto& localModelParams = modelParams;
    for_each(populatedCells->cbegin(), populatedCells->cend(), [&cellsToErase, &localLifeArea, /*&localPopulatedCells, &localModelParams,*/ this] (const int cellN) {
        if (localLifeArea->at(cellN)->neighborsCount() <= Cell::deathLevel || localLifeArea->at(cellN)->neighborsCount() > Cell::normLevel) {
            //kill Cell
            int randomNumber = Helpers::Generators::getRandomDeviceNumber(0, 100);
            qDebug() << "randomNumber " << randomNumber;
            cout << "randomNumber " << randomNumber << "  probabilityToDeath " << static_cast<int>(Helpers::probabilityToDeath * 100) << endl;// TODO: remove dependency from Model
            if (randomNumber < static_cast<int>(Helpers::probabilityToDeath * 100)) {// the same
                localLifeArea->at(cellN)->setState(Cell::emptyState);
                //populatedCells->erase(remove(populatedCells->begin(), populatedCells->end(), cellN), populatedCells->end());
                //localPopulatedCells->erase(cellN);
                cellsToErase.emplace_back(cellN);
//                cout << "Cell#" << cellN << " are dead now. populatedCells size:" << localPopulatedCells->size() << endl;
//                int row = cellN / localModelParams->getAreaWidth();
//                int col = cellN % localModelParams->getAreaWidth();
//                cout << "row#" << row << " col#" << col << endl;
//                QModelIndex modelIndex = createIndex(row, col);
//                emit dataChanged(modelIndex, modelIndex, {Qt::BackgroundRole});
                //emit dataChanged(createIndex(0, 0), createIndex(19, 19), {Qt::BackgroundRole});
                //data(modelIndex, Qt::BackgroundRole);
            }
        }

    });
    //int x = 4;
    //auto y = [&r = x, x = x + 1]()->int
    for_each(cellsToErase.cbegin(), cellsToErase.cend(), [&localModelParams, &localPopulatedCells, this](const int cellNumber){
        localPopulatedCells->erase(cellNumber);
        int row = cellNumber / localModelParams->getAreaWidth();
        int col = cellNumber % localModelParams->getAreaWidth();
        cout << "row#" << row << " col#" << col << endl;
        QModelIndex modelIndex = createIndex(row, col);
        emit dataChanged(modelIndex, modelIndex, {Qt::BackgroundRole});
    });
    cellsToErase.clear();

//    int randomN = Helpers::Generators::getRandomDeviceNumber(0, 399);
//    cout << "rn:" << randomN << endl;
//    lifeArea->at(randomN)->setState(Cell::hardSettledState);
//    int row = randomN / modelParams->getAreaWidth();
//    int col = randomN % modelParams->getAreaWidth();
//    cout << "row###" << row << " col###" << col << endl;
//    QModelIndex modelIndex = createIndex(row, col);
//    emit dataChanged(modelIndex, modelIndex, {Qt::BackgroundRole});
    cout << "out makeIter" << endl;
}
// shared_ptr<vector<shared_ptr<Cell>>> lifeArea;
void LifeModel::timerHit()
{
    QModelIndex topLeft = createIndex(0,0);
    emit dataChanged(topLeft, topLeft, {Qt::DisplayRole});
}
