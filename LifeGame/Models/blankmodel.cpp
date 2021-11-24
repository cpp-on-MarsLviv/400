#include "blankmodel.h"
#include "Helpers/constants.h"

#include <QBrush>

BlankModel::BlankModel(QObject *parent) : QAbstractTableModel(parent)
{

}
int BlankModel::rowCount(const QModelIndex & /*parent*/) const { return 1; }

int BlankModel::columnCount(const QModelIndex & /*parent*/) const { return 1; }

QVariant BlankModel::data(const QModelIndex &index, int role) const
{
    switch (role) {
    case Qt::TextAlignmentRole:
        return Qt::AlignCenter;
    case Qt::SizeHintRole:
        return 90;
    case Qt::DisplayRole:
        return Helpers::blankModelMessageInfo;

    case Qt::BackgroundRole:
        return QBrush(Helpers::blankModelColor);
        break;
    }

    return QVariant();
}

Qt::ItemFlags BlankModel::flags(const QModelIndex &/*index*/) const { return Qt::NoItemFlags; }
