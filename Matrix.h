//
// Created by roy on 08/01/19.
//

#ifndef ROYANDIDANPROJECT2_MATRIX_H
#define ROYANDIDANPROJECT2_MATRIX_H

#include <utility>
#include <cstdio>
#include <cstdlib>
#include "Searchable.h"
#include "Point.h"

#define FIRST_COLUMN 0
#define INFINITY -1


class Matrix : public Searchable<Point> {
private:
    vector<vector<State<Point> *>> matrix;
    State<Point> *initialState;
    State<Point> *goalState;
    size_t rows;
    size_t columns;

public:

    Matrix(Point initial, Point goal, vector<vector<State<Point> *>> mat) {
        this->initialState = new State<Point>(initial);
        this->goalState = new State<Point>(goal);
        this->matrix = mat;
        this->goalState->setCost(mat[goal.getLeft()][goal.getRight()]->getCost
                ());
        this->initialState->setCost(mat[initial.getLeft()][initial.getRight()]
                                            ->getCost());
        this->rows = matrix.size();
        this->columns = matrix[FIRST_COLUMN].size();
    }

    State<Point> *getInitialState() {
        return this->initialState;
    }

    State<Point> *getGoalState() {
        return this->goalState;
    }

    State<Point> *getStateByPoint(Point p1) {
        return matrix[p1.getLeft()][p1.getRight()];

    }

    vector<State<Point> *> getPossibleStates(State<Point> *fromState) override {
        vector<State<Point> *> possibleStates;
        int i = fromState->getState().getLeft();
        int j = fromState->getState().getRight();
        //checks if the indexes are out of the matrix's bounds.
        if (i < 0 || j < 0 || i >= rows || j >= columns) {
            perror("Out of Bounds.");
            exit(1);
        }
        //not first row add above.
        if (i != 0 && matrix[i - 1][j]->getCost() != INFINITY) {
            Point tempPoint(i - 1, j);
            State<Point> *tempState = getStateByPoint(tempPoint);
            if (tempState->getCameFrom() == nullptr) {
                tempState->setCameFrom(fromState);
            }
            possibleStates.emplace_back(tempState);
        }
        //not first column add left.
        if (j != 0 && matrix[i][j - 1]->getCost() != INFINITY) {
            Point tempPoint(i, j - 1);
            State<Point> *tempState = getStateByPoint(tempPoint);
            if (tempState->getCameFrom() == nullptr) {
                tempState->setCameFrom(fromState);
            }
            possibleStates.emplace_back(tempState);
        }
        //not last row, add below
        if (i != this->rows - 1 && matrix[i + 1][j]->getCost() != INFINITY) {
            Point tempPoint(i + 1, j);
            State<Point> *tempState = getStateByPoint(tempPoint);
            if (tempState->getCameFrom() == nullptr) {
                tempState->setCameFrom(fromState);
            }
            possibleStates.emplace_back(tempState);
        }
        //not last column, add right
        if (j != this->columns - 1 && matrix[i][j + 1]->getCost() != INFINITY) {
            Point tempPoint(i, j + 1);
            State<Point> *tempState = getStateByPoint(tempPoint);
            if (tempState->getCameFrom() == nullptr) {
                tempState->setCameFrom(fromState);
            }
            possibleStates.emplace_back(tempState);
        }
        return possibleStates;
    }
};


#endif //ROYANDIDANPROJECT2_MATRIX_H
