#ifndef CELLOBSERVER_H
#define CELLOBSERVER_H

#include <memory>

class Cell;

class CellObserver {
public:
    virtual void stateChanged(std::shared_ptr<const Cell>) = 0;
    virtual ~CellObserver() = default;
};

#endif // CELLOBSERVER_H
