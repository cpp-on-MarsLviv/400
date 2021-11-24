#ifndef LIFEMODEL_H
#define LIFEMODEL_H

#include "modelparams.h"
#include "cell.h"

#include <vector>
#include <set>
#include <memory>

#include <QAbstractTableModel>
#include <QObject>


class Cell;
class QTimer;

using std::vector;
using std::shared_ptr;

class LifeModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit LifeModel(shared_ptr<ModelParams> params, QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

    static const map<Cell::State, QBrush> stateColorMapping;
    static map<Cell::State, QBrush> createStateColorMapping();

    void startLife(size_t);
    void stopLife();
    void changeLifeRate(int);

private:
    void makeIteration();

    shared_ptr<ModelParams> modelParams;
    shared_ptr<vector<shared_ptr<Cell>>> lifeArea;
    shared_ptr<set<int>> populatedCells;
    QTimer *lifeTimer = Q_NULLPTR;
private:
    QTimer *clockTimer;
private slots:
    void timerHit();
};

#endif // LIFEMODEL_H
