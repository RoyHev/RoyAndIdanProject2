//
// Created by roy on 07/01/19.
//

#ifndef ROYANDIDANPROJECT2_STATE_H
#define ROYANDIDANPROJECT2_STATE_H

template <class T>
class State {
private:
    T state;
    double cost;
    State<T>* cameFrom;
public:
    State(T state){
        this->state = state;
    }
    State(T state, double cost){
        this->state = state;
        this->cost = cost;
    }
    void setCost(double cost){
        this->cost = cost;
    }
    void setCameFrom(State* state){
        this->cameFrom = state;
    }
    bool equalsTo(State state2){
        if (this->state == state2.getState()){
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

};



#endif //ROYANDIDANPROJECT2_STATE_H
