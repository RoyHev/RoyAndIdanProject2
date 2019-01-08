//
// Created by roy on 08/01/19.
//

#include "Matrix.h"

#define FIRST_COLUMN 0

State<Point> Matrix::getGoalState() {
    return this->goalState;
}

State<Point> Matrix::getInitialState() {
    return this->initialState;
}

Matrix::Matrix(Point initial, Point goal, vector<vector<double>> mat) {
    this->initialState = State<Point>(initial);
    this->goalState = State<Point>(goal);
    this->matrix = mat;
    this->goalState.setCost(mat[goal.getLeft()][goal.getRight()]);
    this->initialState.setCost(mat[initial.getLeft()][initial.getRight()]);
    this->rows = matrix.size();
    this->columns = matrix[FIRST_COLUMN].size();

}

//TODO - take care of option that it is INFINITY.
//TODO - take care of out of bounds of I or J.
vector<State<Point>> Matrix::getPossibleStates(State<Point> fromState) {
    vector<State<Point>> possibleStates;
    double i = fromState.getState().getLeft();
    double j = fromState.getState().getRight()
    //not first row add above.
    if (i != 0){
        Point tempPoint(i-1,j);
        State<Point> tempState(tempPoint);
        tempState.setCost(this->matrix[i-1][j]);
        tempState.setCameFrom(fromState);
        possibleStates.push_back(tempState);
    }
    //not first column add left.
    if (j != 0){
        Point tempPoint(i,j-1);
        State<Point> tempState(tempPoint);
        tempState.setCost(this->matrix[i][j-1]);
        tempState.setCameFrom(fromState);
        possibleStates.push_back(tempState);
    }
    //not last row, add below
    if (i != this->rows - 1){
        Point tempPoint(i+1,j);
        State<Point> tempState(tempPoint);
        tempState.setCost(this->matrix[i+1][j]);
        tempState.setCameFrom(fromState);
        possibleStates.push_back(tempState);
    }
    //not last column, add right
    if (j != this->columns - 1){
        Point tempPoint(i,j+1);
        State<Point> tempState(tempPoint);
        tempState.setCost(this->matrix[i][j+1]);
        tempState.setCameFrom(fromState);
        possibleStates.push_back(tempState);
    }
    return possibleStates;

}
