#ifndef BLANKMODEL_H
#define BLANKMODEL_H

#include <QAbstractTableModel>

class BlankModel : public QAbstractTableModel
{
public:
    explicit BlankModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

};

#endif // BLANKMODEL_H
