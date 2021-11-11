#ifndef LIFEMODEL_H
#define LIFEMODEL_H

#include <QAbstractTableModel>
#include <QObject>

class LifeModel : public QAbstractTableModel
{
public:
    explicit LifeModel(int initAreaWidth, QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

private:
    int areaWidth;
    //int *areaState[][];
};

#endif // LIFEMODEL_H
