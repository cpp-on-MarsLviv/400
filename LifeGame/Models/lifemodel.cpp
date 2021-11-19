#include "lifemodel.h"
#include "cellarea.h"
#include "cell.h"
#include "Helpers/functions.h"

#include <QBrush>

LifeModel::LifeModel(shared_ptr<ModelParams> newModelParams, QObject *parent) :
    QAbstractTableModel{parent},
    modelParams{newModelParams} {
    lifeArea = CellArea::getSharedCells(modelParams->getAreaWidth());
    qDebug() << "made area with size:" << lifeArea->size();
    CellArea::connectCells();
//    for_each(lifeArea->cbegin(), lifeArea->cend(), [idx = 0](shared_ptr<Cell> cell) mutable {
//        qDebug() << "i:" << idx++ << "  :" << cell->neighborsCount(); });
//    for_each(lifeArea->cbegin(), lifeArea->cend(), [idx = 0](shared_ptr<Cell> cell) mutable {
//        qDebug() << "i:" << idx++ << "  state:" << Helpers::to_underlying(cell->getState()); });  // -> 0

    CellArea::seedCells(modelParams->getDensity());

//    if (QBrush(Qt::red) == QBrush(stateColorMapping.at(Cell::State::HARD_SETTLED)))
//        qDebug() << "+++";
//    else qDebug() << "---";
}

int LifeModel::rowCount(const QModelIndex & /*parent*/) const { return modelParams->getAreaWidth(); }

int LifeModel::columnCount(const QModelIndex & /*parent*/) const { return modelParams->getAreaWidth(); }

QVariant LifeModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int col = index.column();

    switch (role) {
    case Qt::DisplayRole:
//        return QString("Row%1, Column%2")
//                    .arg(index.row() + 1)
//                    .arg(index.column() + 1);
        return QString("");

    case Qt::BackgroundRole:
        size_t idx = row * modelParams->getAreaWidth() + col;
        Cell::State state = lifeArea->at(idx)->getState();
        auto color = stateColorMapping.at(state);
        //qDebug() << "idx:" << idx << ", state:" << Helpers::to_underlying(state) << ", color:" << color;
        return QBrush(color);
        break;
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
    mapping[Cell::State::EMPTY] = Qt::white;
    mapping[Cell::State::LOW_SETTLED] = Qt::yellow;
    mapping[Cell::State::NORM_SETTLED] = Qt::green;
    mapping[Cell::State::HARD_SETTLED] = Qt::red;
    return mapping;
}

