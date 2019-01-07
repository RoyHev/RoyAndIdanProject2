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
    State cameFrom;
public:
    State(T state);
    void setCost(double cost);
    void setCameFrom(State state);
    bool equalsTo(State state2);
    double getCost();
    T getState();

};



#endif //ROYANDIDANPROJECT2_STATE_H
