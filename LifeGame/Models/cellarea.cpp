#include "cell.h"
#include "cellarea.h"

#include <algorithm>

#include <QDebug>

using std::make_shared;

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
        std::for_each(cells.begin(), cells.end(), [](shared_ptr<Cell> cell){ cell->clear(); });
        currentWidth = width;
        cells.resize(currentWidth * currentWidth, Cell::create());
        //cells.emplace_back(Cell::create()); // ok

        return cells;
    } else {
        currentWidth = width;
        cells.resize(currentWidth * currentWidth);
        std::for_each(cells.begin(), cells.end(), [](shared_ptr<Cell> cell){ cell->clear(); });

        return cells;
    }
}

shared_ptr<vector<shared_ptr<Cell> > > CellArea::getSharedCells(size_t width)
{
    if (currentWidth == 0) {
        currentWidth = width;
        vector<shared_ptr<Cell>> localCells(currentWidth * currentWidth, Cell::create());
        sharedCells = make_shared<vector<shared_ptr<Cell>>>(localCells);

        return sharedCells;
    } else if (currentWidth < width) {
        std::for_each(sharedCells->begin(), sharedCells->end(), [](shared_ptr<Cell> cell){ cell->clear(); });
        currentWidth = width;
        sharedCells->resize(currentWidth * currentWidth, Cell::create());

        return sharedCells;
    } else {
        currentWidth = width;
        sharedCells->resize(currentWidth * currentWidth);
        std::for_each(sharedCells->begin(), sharedCells->end(), [](shared_ptr<Cell> cell){ cell->clear(); });

        return sharedCells;
    }
}

void CellArea::connectCells()
{
    qDebug() << "start";


}

void CellArea::seedCells()
{

}

void CellArea::changeLifeRate(int)
{

}

void CellArea::start()
{

}

void CellArea::stop()
{

}
