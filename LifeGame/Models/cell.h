#ifndef CELL_H
#define CELL_H

#include <set>
#include <map>
#include <vector>

#include <memory>

class CellObserver;

using std::set;
using std::map;
using std::shared_ptr;
using std::vector;

template <typename E>
constexpr auto to_underlying(E e) noexcept { return static_cast<std::underlying_type_t<E>>(e); }

/**
 * Represent elementary Cell with set of states.
 * Creation only with static method Cell::create.
 * Settling in std::sharsd_ptr
 */
class Cell : public std::enable_shared_from_this<Cell> {
    /**
     * Represent Cell states
     */
    enum class State { EMPTY, LOW_SETTLED, NORM_SETTLED, HARD_SETTLED };
    /**
     * In order to save memory and accelerate performance all Cell instances use the same State objects
     */
    static const State emptyState = State::EMPTY;
    static const State lowSettledState = State::LOW_SETTLED;
    static const State normSettledState = State::NORM_SETTLED;
    static const State hardSettledState = State::HARD_SETTLED;

    static constexpr float probabilityToDeath = 0.3; // TODO: implement this feature
    static constexpr float probabilityToBorn = 0.3;
    /**
     * If settled Cell has neighbors from 0..2 it can die because of loneliness with probabilityToDeath
     */
    static const int deathLevel = 2;
    /**
     * If settled Cell has neighbors from 3..4 it can born a neighbor with probabilityToBorn
     */
    static const int lowLevel = 4;
    /**
     * If settled Cell has neighbors from 5..6 it can born a neighbor with probabilityToBorn
     */
    static const int normLevel = 6;
    /**
     * If settled Cell has neighbors from 7..8 it can die because of crowding with probabilityToDeath
     */
    static const int hardLevel = 8;

    static const map<int, State> stateMapping;      //

    static map<int, State> createStateMapping();    //

    State state;

    set<shared_ptr<Cell>>  neighbors;
    set<shared_ptr<CellObserver>>  observers;

    void onStateChanged() const;                    //
    void notifyNeighbors() const;                   //
    void notifyObservers() const;                   //

    Cell();                                         //
public:
    Cell(const Cell&) = delete;
    Cell(Cell&&) = delete;
    Cell& operator=(const Cell&) = delete;
    Cell& operator=(Cell&&) = delete;

    ~Cell() = default;

    static shared_ptr<Cell> create();               //
    std::shared_ptr<const Cell> getSharedPtr() const;//

    void addNeighbor(shared_ptr<Cell>);             //
    void removeNeighbor(shared_ptr<Cell>);          //
    void removeAllNeighbors();                      //

    void addObserver(shared_ptr<CellObserver>);     //
    void removeObserver(shared_ptr<CellObserver>);  //
    void removeAllObservers();                      //

    State getState() const;                         //
    void setState(State);                           //
    void setState(int);                             //
    void updateState();                             //
};

#endif // CELL_H
