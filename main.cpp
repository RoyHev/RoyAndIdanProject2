#include <iostream>

using namespace std;

#include "Point.h"
#include "Matrix.h"
#include "Searcher.h"
#include "CacheManager.h"
#include "ClientHandler.h"
#include "DepthFirstSearch.h"
#include "Server.h"
#include "Solver.h"
#include "Searchable.h"
#include "BreadthFirstSearch.h"
#include "BestFirstSearch.h"
#include "MatrixSolver.h"
#include "MatrixClientHandler.h"
#include "Server.h"
#include "ParallelServer.h"
#include "AStar.h"

vector<int> splitString(string info) {
    vector<int> nodeValues;
    string temp;
    //go over the vector until a comma is seen and then push it to the node values.
    for (unsigned long i = 0; i < info.length(); i++) {
        if (info.at(i) != COMMA_DELIMITER) {
            temp += info.at(i);
        } else {
            nodeValues.push_back(stoi(temp));
            temp.erase();
        }
    }
    nodeValues.push_back(stoi(temp));
    //returns the node values of the string within the vector that was given to us from the server.
    return nodeValues;
}

/*
 * Reads the problem and creates it into a matrix problem consisting of a matrix of doubles,
 * an initial state and a goal state.
 */
Matrix *lexer(vector<string> problemInfo) {
    vector<vector<State<Point> *>> matrixVector;
    vector<int> nodeValues;
    vector<int> pointIndexes;
    vector<State<Point> *> specificLine;
    //go over the problem info excluding the initial point and the goal point.
    for (int i = 0; i < (problemInfo.size() - 2); i++) {
        nodeValues = splitString(problemInfo.at(i));
        //create one line of the matrix.
        for (int j = 0; j < nodeValues.size(); j++) {
            specificLine.push_back(new State<Point>(Point(i, j), nodeValues.at(j)));
        }
        //insert it to the matrix vector to create the "matrix"
        matrixVector.push_back(specificLine);
        //erase all contents of the vector.
        specificLine.erase(specificLine.begin(), specificLine.end());
    }
    //create the initial and goal points to eventually create the matrix.
    pointIndexes = splitString(problemInfo[problemInfo.size() - 2]);
    Point initialPoint(pointIndexes[0], pointIndexes[1]);
    pointIndexes.erase(pointIndexes.begin(), pointIndexes.end());
    pointIndexes = splitString(problemInfo[problemInfo.size() - 1]);
    Point goalPoint(pointIndexes[0], pointIndexes[1]);
    //create the matrix and return it.
    Matrix *matrix = new Matrix(initialPoint, goalPoint, matrixVector);
    return matrix;
}


/**
 * writes a pair (problem and its solution) to the cache text File.
 * @param problem describes problem
 * @param solution describes solution
 */
void writeToFile(string algoName, string solution) {
    ofstream outputStream;
    outputStream.open("solution.txt", ios::out | ios::app);
    if (outputStream.is_open()) {
        outputStream << algoName << ":\n";
        outputStream << solution << '\n';
        outputStream.close();
    } else {
        perror("couldn't open cache File");
        exit(1);
    }
}

void loadFromFile() {
    ifstream inFile;
    inFile.open("matrixs.txt");

    //problem with opening the file
    if (inFile.bad()) {
        perror("error opening file");
        exit(1);
    }
    /*
     * run over the lines in the file
     */
    MatrixSolver dfs(new DepthFirstSearch<Point>());
    MatrixSolver astar(new AStar<Point>());
    MatrixSolver bestfs(new BestFirstSearch<Point>());
    MatrixSolver bfs(new BreadthFirstSearch<Point>());

    vector<string> problem;
    int matrixNum = 1;
    for (string line; getline(inFile, line);) {
        if (line == "@") {
            writeToFile("matrix number " + to_string(matrixNum) + '\n' + "BEST FIRST",
                        bestfs.NodesCostsSolution(lexer(problem)));
            writeToFile("DFS", dfs.NodesCostsSolution(lexer(problem)));
            writeToFile("BFS", bfs.NodesCostsSolution(lexer(problem)));
            writeToFile("A*", astar.NodesCostsSolution(lexer(problem)));

            problem.clear();
            matrixNum++;
            continue;
        }
        problem.push_back(line);

    }

    inFile.close();
}


int main() {
    loadFromFile();
//    Searcher<Point> *bfs = new AStar<Point>();
//    MatrixSolver matrixSolver(bfs);
//    MatrixClientHandler matrixClientHandler(matrixSolver);
//    server_side::ParallelServer parallelServer;
//    parallelServer.open(5402, matrixClientHandler);
//    std::cout << bfs->getNumOfNodes() << std::endl;
//    std::cout << bfs->getTotalPathCost() << std::endl;
//    delete(bfs);
    return 0;
}