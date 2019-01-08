//
// Created by roy on 08/01/19.
//

#ifndef ROYANDIDANPROJECT2_MATRIX_H
#define ROYANDIDANPROJECT2_MATRIX_H


#include "Searchable.h"
#include "Point.h"

class Matrix : public Searchable<Point> {
private:
    vector<vector<double>> matrix;
    State<Point> initialState;
    State<Point> goalState;
    size_t rows;
    size_t columns;

public:
    Matrix(Point initial, Point goal, vector<vector<double>> mat);
    virtual State<Point> getInitialState();
    virtual State<Point> getGoalState();
    virtual vector<State<Point>> getPossibleStates(State<Point> fromState);

};


#endif //ROYANDIDANPROJECT2_MATRIX_H
