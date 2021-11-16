#ifndef CELLAREA_H
#define CELLAREA_H

#include <vector>
#include <memory>

using std::vector;
using std::shared_ptr;

class Cell;
/**
 * @brief Represent the area with Cells
 */
class CellArea
{
    static shared_ptr<vector<shared_ptr<Cell>>> cells;

    CellArea() = default;
public:
    CellArea(const CellArea&) = delete;
    CellArea(CellArea&&) = delete;
    CellArea& operator=(const CellArea&) = delete;
    CellArea& operator=(CellArea&&) = delete;

    static shared_ptr<vector<shared_ptr<Cell>>> getBunch(size_t);
};

#endif // CELLAREA_H
