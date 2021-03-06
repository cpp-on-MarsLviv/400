#ifndef CELLAREA_H
#define CELLAREA_H

#include <vector>
#include <set>
#include <memory>

using std::vector;
using std::set;
using std::shared_ptr;

class Cell;
/**
 * @brief Represent the area with Cells
 */
class CellArea
{
    static vector<shared_ptr<Cell>> cells;
    static shared_ptr<vector<shared_ptr<Cell>>> sharedCells;
    //static shared_ptr<vector<int>> populatedCells;

    static size_t currentWidth;

    CellArea() = default;
public:
    CellArea(const CellArea&) = delete;
    CellArea(CellArea&&) = delete;
    CellArea& operator=(const CellArea&) = delete;
    CellArea& operator=(CellArea&&) = delete;

    static vector<shared_ptr<Cell>> getCells(size_t);
    static shared_ptr<vector<shared_ptr<Cell>>> getSharedCells(size_t);
    static void connectCells();
    static shared_ptr<set<int>> seedCells(double density);
//    static void changeLifeRate(int);

//    static void start();
//    static void stop();
};

#endif // CELLAREA_H
