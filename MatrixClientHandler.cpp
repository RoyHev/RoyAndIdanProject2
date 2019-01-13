//
// Created by roy on 13/01/19.
//

#include <unistd.h>
#include "MatrixClientHandler.h"

void MatrixClientHandler::handleClient(int socketID) {
    //get the problem info from the server.
    vector<string> problemInfo = this->serverCommunication.readFromServer(socketID);
    //create the matrix.
    Matrix *matrix = lexer(problemInfo);
    //send the solution back to server.
    serverCommunication.writeToServer(socketID, (getMatrixSolution(matrix) + ENTER));
    //close the socket.
    close(socketID);
}

Matrix *MatrixClientHandler::lexer(vector<string> problemInfo) {
    vector<vector<State<Point>*>> matrixVector;
    vector<int> nodeValues;
    vector<int> pointIndexes;
    vector<State<Point>*> specificLine;
    //go over the problem info excluding the initial point and the goal point.
    for (int i = 0; i< (problemInfo.size() - 2); i++){
        nodeValues = splitString(problemInfo.at(i));
        //create one line of the matrix.
        for (int j = 0; j< nodeValues.size(); j++){
            specificLine.push_back(new State<Point>(Point(i,j),nodeValues.at(j)));
        }
        //insert it to the matrix vector to create the "matrix"
        matrixVector.push_back(specificLine);
        //erase all contents of the vector.
        specificLine.erase(specificLine.begin(),specificLine.end());
    }
    //create the initial and goal points to eventually create the matrix.
    pointIndexes = splitString(problemInfo[problemInfo.size() - 2]);
    Point initialPoint(pointIndexes[0],pointIndexes[1]);
    pointIndexes.erase(pointIndexes.begin(), pointIndexes.end());
    pointIndexes = splitString(problemInfo[problemInfo.size() - 1]);
    Point goalPoint(pointIndexes[0],pointIndexes[1]);
    //create the matrix and return it.
    Matrix* matrix = new Matrix(initialPoint, goalPoint, matrixVector);
    return matrix;
}

vector<int> MatrixClientHandler::splitString(string info) {
    vector<int> nodeValues;
    string temp;
    //go over the vector until a comma is seen and then push it to the node values.
    for (unsigned long i = 0; i < temp.length(); i++) {
        if (info.at(i) == COMMA_DELIMITER){
            nodeValues.push_back(stoi(temp));
            temp.erase();
            continue;
        }
        temp += info.at(i);
    }
    //returns the node values of the string within the vector that was given to us from the server.
    return nodeValues;
}


string MatrixClientHandler::getMatrixSolution(Matrix *matrix) {
    //if the problem has previously been solved and saved, return the solution.
    if (this->cacheManager->solutionExists(*matrix)){
        return cacheManager->getSolution(*matrix);
        //solves the problem and saves the problem and its solution in the map and writes
        //it to the cache text file.
    } else {
        string matrixSolution = this->matrixSolver.solve(matrix);
        cacheManager->saveSolution(*matrix, matrixSolution);
        return matrixSolution;
    }
}

MatrixClientHandler::~MatrixClientHandler() {
    for (unsigned long i = 0; i < this.)

}

