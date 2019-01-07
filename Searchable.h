//
// Created by roy on 07/01/19.
//

#ifndef ROYANDIDANPROJECT2_SEARCHABLE_H
#define ROYANDIDANPROJECT2_SEARCHABLE_H

#include "State.h"
#include <vector>

using namespace std;

template <class T>
class Searchable {
public:
    virtual State<T> getInitialState() = 0;
    virtual State<T> getGoalState() = 0;
    virtual vector<T> getPossibleStates() = 0;



};


#endif //ROYANDIDANPROJECT2_SEARCHABLE_H
