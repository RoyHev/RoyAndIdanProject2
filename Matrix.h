//
// Created by roy on 08/01/19.
//

#ifndef ROYANDIDANPROJECT2_MATRIX_H
#define ROYANDIDANPROJECT2_MATRIX_H


#include "Searchable.h"
#include "Point.h"

class Matrix : public Searchable<Point> {
private:

public:
    virtual State<Point> getInitialState() = 0;
    virtual State<Point> getGoalState() = 0;
    virtual vector<Point> getPossibleStates() = 0;

};


#endif //ROYANDIDANPROJECT2_MATRIX_H
