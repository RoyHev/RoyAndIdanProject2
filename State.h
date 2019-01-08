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
    State<T> *cameFrom;
    bool visited;
public:
    State(T state) {
        this->state = state;
        this->visited = false;
    }

    void setVisited(bool didVisit){
        this->visited = didVisit;
    }

    bool getVisited(){
        return this->visited;
    }

    State(T state, double cost) {
        this->state = state;
        this->cost = cost;
    }

    void setCost(double cost) {
        this->cost = cost;
    }

    void setCameFrom(State *state) {
        this->cameFrom = state;
    }

    bool equalsTo(State state2) {
        if (this->state == state2.getState()) {
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
