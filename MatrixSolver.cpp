//
// Created by idantp on 1/12/19.
//

#include "MatrixSolver.h"

string MatrixSolver::solve(Searchable<Point> *problem) {
    vector<State<Point> *> path;
    path = this->searchAlgorithm->search(problem);
    return getPathInstructions(path);
}

string MatrixSolver::getNextStep(Point previous, Point current) {
    int previousLeft = previous.getLeft();
    int previousRight = previous.getRight();
    int currentLeft = current.getLeft();
    int currentRight = current.getRight();
    if (previousLeft > currentLeft) { return UP; }
    else if (previousLeft < currentLeft) { return DOWN; }
    else if (previousRight > currentRight) { return LEFT; }
    else { return RIGHT; }
}

string MatrixSolver::getPathInstructions(vector<State<Point> *> path) {
    if (path.empty()) { return NO_PATH; }
    string pathInstructions;
    unsigned long pathSize = path.size();
    for (unsigned long i = 1; i <= pathSize - 2; i++) {
        pathInstructions += getNextStep(path.at(i - 1)->getState(), path.at(i)->getState());
        pathInstructions += COMMA;
    }
    pathInstructions += getNextStep(path.at(pathSize - 2)->getState(), path.at(pathSize - 1)
            ->getState());
    return pathInstructions;
}

MatrixSolver::MatrixSolver(Searcher<Point> *searchAlgorithm) : searchAlgorithm(searchAlgorithm) {}

