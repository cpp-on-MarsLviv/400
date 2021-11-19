#include "cell.h"
#include "cellobserver.h"

#include <QDebug>



Cell::Cell() : state {emptyState} {}

shared_ptr<Cell> Cell::create() { return std::shared_ptr<Cell>(new Cell()); }

std::shared_ptr<const Cell> Cell::getSharedPtr() const {return shared_from_this(); }

void Cell::clear()
{
    state = emptyState;
    removeAllNeighbors();
    removeAllObservers();
}

void Cell::addNeighbor(shared_ptr<const Cell> cell) {
    //qDebug() << "cell:" << cell.get();
    auto pair = neighbors.insert(cell);
    //if (pair.second) qDebug() << "inserted";
    //else qDebug() << "exist";
}

void Cell::removeNeighbor(shared_ptr<const Cell> cell) { neighbors.erase(cell); }

void Cell::removeAllNeighbors() { neighbors.clear(); }

void Cell::addObserver(shared_ptr<CellObserver> observer) { observers.insert(observer); }

void Cell::removeObserver(shared_ptr<CellObserver> observer) { observers.erase(observer); }

void Cell::removeAllObservers() { observers.clear(); }

size_t Cell::neighborsCount() const { return neighbors.size(); }

size_t Cell::observersCount() const { return observers.size(); }

Cell::State Cell::getState() const { return state;}

void Cell::setState(State newState) const
{
    if (state == newState)
            return;

    state = newState;
    //onStateChanged();//  TODO: optimize it like create a queue to add Cell to change it state and handle them at once
}

void Cell::setState(int newState) const { setState(stateMapping.at(newState)); }

const map<int, Cell::State> Cell::stateMapping = Cell::createStateMapping();

map<int, Cell::State> Cell::createStateMapping()
{
    map<int, Cell::State> mapping;
    mapping[0] = emptyState;
    mapping[1] = emptyState;
    mapping[2] = emptyState;
    mapping[3] = lowSettledState;
    mapping[4] = lowSettledState;
    mapping[5] = normSettledState;
    mapping[6] = normSettledState;
    mapping[7] = hardSettledState;
    mapping[8] = hardSettledState;
    return mapping;
}

void Cell::updateState() const
{
    int neighborsCount = 0;
    for (auto it = neighbors.cbegin(); it != neighbors.cend(); ++it)
        if ( (*it)->getState() != emptyState)
            ++neighborsCount;

    setState(neighborsCount);
}

void Cell::onStateChanged() const
{
    notifyNeighbors();
    notifyObservers();
}

void Cell::notifyNeighbors() const
{
    for (auto it = neighbors.begin(); it != neighbors.end(); ++it)
        (*it)->updateState();
}

void Cell::notifyObservers() const
{
    for (auto it = observers.cbegin(); it != observers.cend(); ++it)
        (*it)->stateChanged(getSharedPtr());
}
