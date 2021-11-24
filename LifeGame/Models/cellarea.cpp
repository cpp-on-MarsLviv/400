#include "cell.h"
#include "cellarea.h"
#include "Helpers/generators.h"
#include "Helpers/constants.h"
#include "Helpers/functions.h"

#include <algorithm>
#include <iostream>
#include <set>

#include <QDebug>

using std::make_shared;
using std::for_each;

vector<shared_ptr<Cell>> CellArea::cells;
shared_ptr<vector<shared_ptr<Cell>>> CellArea::sharedCells;
size_t CellArea::currentWidth = 0;

vector<shared_ptr<Cell>> CellArea::getCells(size_t width)
{
    if (currentWidth == 0) {
        currentWidth = width;
        std::vector<shared_ptr<Cell>> localCells(currentWidth * currentWidth, Cell::create());
        cells = localCells;

        return cells;
    } else if (currentWidth < width) {
        for_each(cells.begin(), cells.end(), [](shared_ptr<Cell> cell){ cell->clear(); });
        currentWidth = width;
        cells.resize(currentWidth * currentWidth, Cell::create());
        //cells.emplace_back(Cell::create()); // ok

        return cells;
    } else {
        currentWidth = width;
        cells.resize(currentWidth * currentWidth);
        for_each(cells.begin(), cells.end(), [](shared_ptr<Cell> cell){ cell->clear(); });

        return cells;
    }
}

shared_ptr<vector<shared_ptr<Cell> > > CellArea::getSharedCells(size_t width)
{
    if (currentWidth == 0) {
        qDebug() << "creating new Life area";
        currentWidth = width;
        sharedCells = make_shared<vector<shared_ptr<Cell>>>();
        sharedCells->reserve(currentWidth * currentWidth);
        size_t size = currentWidth * currentWidth;
        for (size_t i = 0; i < size; ++i) { sharedCells->emplace_back(Cell::create()); };
        //for_each(sharedCells->cbegin(), sharedCells->cend(), [idx = 0](shared_ptr<Cell> cell) mutable {qDebug() << "cell[" << idx++ << "]:" << cell.get();});

        return sharedCells;
    } else if (currentWidth > width) {
        qDebug() << "currentWidth:" << currentWidth << " new width:" << width << " -> decreasing Life area";
        currentWidth = width;
        sharedCells->resize(currentWidth * currentWidth);
        for_each(sharedCells->begin(), sharedCells->end(), [](shared_ptr<Cell> cell){ cell->clear(); });
        //for_each(sharedCells->cbegin(), sharedCells->cend(), [idx = 0](shared_ptr<Cell> cell) mutable {qDebug() << "cell[" << idx++ << "]:" << cell.get();});

        return sharedCells;
    } else {
        qDebug() << "increasing Life area";
        for_each(sharedCells->begin(), sharedCells->end(), [](shared_ptr<Cell> cell){ cell->clear(); });
        size_t additionalSize = width * width - currentWidth * currentWidth;
        currentWidth = width;
        for (size_t i = 0; i < additionalSize; ++i) { sharedCells->emplace_back(Cell::create()); };
        //for_each(sharedCells->cbegin(), sharedCells->cend(), [idx = 0](shared_ptr<Cell> cell) mutable {qDebug() << "cell[" << idx++ << "]:" << cell.get();});

        return sharedCells;
    }
}

/**
 * @brief CellArea::connectCells for each Cell assign all neighbors in CellArea
 * Each Cell can have up to 8 neighbors. For more info see picture on UML diagram.
 */
void CellArea::connectCells()
{
    auto cellInRange = [](int i) -> bool { return i >= 0 && i < static_cast<int>(currentWidth); };
    std::for_each(sharedCells->begin(), sharedCells->end(), [idx = 0, cellInRange](shared_ptr<Cell> cell) mutable {
        int row = idx / currentWidth;
        int col = idx % currentWidth;
        //qDebug() << "idx:" << idx << " row:" << row << " col:" << col;
        if (cellInRange(row - 1) && cellInRange(col - 1)){              //qDebug() << "case1 " << currentWidth * (row - 1) + (col - 1);
            cell->addNeighbor(sharedCells->at(currentWidth * (row - 1) + (col - 1))->getSharedPtr());}
        if (cellInRange(row - 1) && cellInRange(col)){                  //qDebug() << "case2 " << currentWidth * (row - 1) + col;
            cell->addNeighbor(sharedCells->at(currentWidth * (row - 1) + col)->getSharedPtr());}
        if (cellInRange(row - 1) && cellInRange(col + 1)){              //qDebug() << "case3 " << currentWidth * (row - 1) + (col + 1);
            cell->addNeighbor(sharedCells->at(currentWidth * (row - 1) + (col + 1))->getSharedPtr());}
        if (cellInRange(row) && cellInRange(col - 1)){                  //qDebug() << "case4 " << currentWidth * row + (col - 1);
            cell->addNeighbor(sharedCells->at(currentWidth * row + (col - 1))->getSharedPtr());}
        if (cellInRange(row) && cellInRange(col + 1)){                  //qDebug() << "case5 " << currentWidth * row + (col + 1);
            cell->addNeighbor(sharedCells->at(currentWidth * row + col + 1)->getSharedPtr());}
        if (cellInRange(row + 1) && cellInRange(col - 1)){              //qDebug() << "case6 " << currentWidth * (row + 1) + (col - 1);
            cell->addNeighbor(sharedCells->at(currentWidth * (row + 1) + (col - 1))->getSharedPtr());}
        if (cellInRange(row + 1) && cellInRange(col)){                  //qDebug() << "case7 " << currentWidth * (row + 1) + col;
            cell->addNeighbor(sharedCells->at(currentWidth * (row + 1) + col)->getSharedPtr());}
        if (cellInRange(row + 1) && cellInRange(col + 1)){              //qDebug() << "case8 " << currentWidth * (row + 1) + (col + 1);
            cell->addNeighbor(sharedCells->at(currentWidth * (row + 1) + (col + 1))->getSharedPtr());}
        ++idx;
    });
//    std::for_each(sharedCells->begin(), sharedCells->end(), [idx = 0](shared_ptr<Cell> cell) mutable {
//        qDebug() << "cell#" << idx << " has:" << cell->neighborsCount() << "neighbors";
//        ++idx;
//    });
}

shared_ptr<set<int>> CellArea::seedCells(double density)
{
    size_t areaSize = currentWidth * currentWidth;
    size_t bornNewCells = areaSize * density;
    shared_ptr<set<int>> numbers = Helpers::Generators::getMT19937Bunch(Helpers::seed7, 0, areaSize - 1, bornNewCells);
    std::copy(numbers->cbegin(), numbers->cend(), std::ostream_iterator<int> (std::cout, " ") );

//    for_each(sharedCells->cbegin(), sharedCells->cend(), [idx = 0](shared_ptr<Cell> cell) mutable {
//            qDebug() << "i:" << idx++ << "  BEFOREstate:" << Helpers::to_underlying(cell->getState()); }); // -> 0
    for_each(numbers->cbegin(), numbers->cend(), [](const int item) {
        sharedCells->at(item)->setState(Cell::State::LOW_SETTLED/*Cell::lowSettledState*/);
//        qDebug() << "set cell #:" << item << " to " << Helpers::to_underlying(Cell::State::LOW_SETTLED) <<
//                    " and it state now is:" << Helpers::to_underlying(sharedCells->at(item)->getState());
    } );
//    for_each(sharedCells->cbegin(), sharedCells->cend(), [idx = 0](shared_ptr<Cell> cell) mutable {
//            qDebug() << "i:" << idx++ << "  AFTERstate:" << Helpers::to_underlying(cell->getState()); });   // -> 123 ???
    return numbers;
}
// static shared_ptr<vector<shared_ptr<Cell>>> sharedCells;


//void CellArea::changeLifeRate(int)
//{

//}

//void CellArea::start()
//{

//}

//void CellArea::stop()
//{

//}
