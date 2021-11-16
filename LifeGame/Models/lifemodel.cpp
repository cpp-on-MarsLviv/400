#include "lifemodel.h"

#include <QBrush>

LifeModel::LifeModel(int initAreaWidth, QObject *parent) :
    QAbstractTableModel{parent},
    areaWidth{initAreaWidth} {
    //lifeArea = Cell::create(initAreaWidth * initAreaWidth);
}

int LifeModel::rowCount(const QModelIndex & /*parent*/) const { return areaWidth; }

int LifeModel::columnCount(const QModelIndex & /*parent*/) const { return areaWidth; }

QVariant LifeModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int col = index.column();

    switch (role) {
    case Qt::DisplayRole:
        return QString("");

    case Qt::BackgroundRole:
            if (row == 1 && col == 2)
                return QBrush(Qt::red);
            break;
    }

    return QVariant();
}

Qt::ItemFlags LifeModel::flags(const QModelIndex &index) const { return Qt::NoItemFlags; }
