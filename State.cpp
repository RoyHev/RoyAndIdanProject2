//
// Created by roy on 07/01/19.
//

#include "State.h"

template<class T>
State<T>::State(T state) {
    this->state = state;
}

template<class T>
void State<T>::setCost(double cost) {
    this->cost = cost;

}

template<class T>
void State<T>::setCameFrom(State state) {
    this->cameFrom = cameFrom;
}

template<class T>
bool State<T>::equalsTo(State state2) {
    if (this->state == state2.getState()){
        return true;
    } else {
        return false;
    }
}

template<class T>
double State<T>::getCost() {
    return this->cost;
}

template<class T>
T State<T>::getState() {
    return this->state;
}
