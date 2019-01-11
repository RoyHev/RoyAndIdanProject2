//
// Created by roy on 07/01/19.
//

#ifndef ROYANDIDANPROJECT2_STATE_H
#define ROYANDIDANPROJECT2_STATE_H

template<class T>
class State {
private:
    T state;
    double cost;
    double pathCost;
    State<T> *cameFrom;
public:
    State(T state) : state(state){
        this->pathCost = -1;
    }

    State(T state, double cost) : state(state) {
        this->state = state;
        this->cost = cost;
        this->pathCost = -1;
    }

    void setPathCost(double pathCost) {
        State::pathCost = pathCost;
    }

    double getPathCost() const {
        return pathCost;
    }

    void setCost(double cost) {
        this->cost = cost;
    }

    void setCameFrom(State *state) {
        this->cameFrom = state;
    }

    bool equalsTo(State* state2) {
        if (this->state == state2->getState()) {
            return true;
        } else {
            return false;
        }
    }

    double getCost() const {
        return this->cost;
    }

    T getState() const {
        return this->state;
    }

    const bool operator==(const State &other) {
        if (this->cost == other.getCost()) {
            return true;
        }
        return false;
    }

    const bool operator<(const State &other) {
        if (this->getCost() < other.getCost()) {
            return true;
        }
        return false;
    }

    const bool operator>(const State &other) {
        if (this->getCost() > other.getCost()) {
            return true;
        }
        return false;
    }

    const bool operator<=(const State &other) {
        if (this->getCost() <= other.getCost()) {
            return true;
        }
        return false;
    }

    const bool operator>=(const State &other) {
        if (this->getCost() >= other.getCost()) {
            return true;
        }
        return false;
    }

    State<T> *getCameFrom() const {
        return cameFrom;
    }
};


#endif //ROYANDIDANPROJECT2_STATE_H
