#ifndef LIFEMODEL_H
#define LIFEMODEL_H

#include "modelparams.h"

#include <QAbstractTableModel>
#include <QObject>

#include <vector>
#include <memory>

class Cell;

using std::vector;
using std::shared_ptr;

class LifeModel : public QAbstractTableModel
{
public:
    explicit LifeModel(ModelParams params, QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

private:
    int areaWidth;
    size_t timing;
    shared_ptr<vector<shared_ptr<Cell>>> lifeArea;
};

#endif // LIFEMODEL_H
