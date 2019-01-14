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


int main() {

    Searcher<Point> *bfs = new AStar<Point>();
    MatrixSolver matrixSolver(bfs);
    MatrixClientHandler matrixClientHandler(matrixSolver);
    server_side::ParallelServer parallelServer;
    parallelServer.open(5402, matrixClientHandler);
    std::cout << bfs->getNumOfNodes() << std::endl;
    std::cout << bfs->getTotalPathCost() << std::endl;
    delete(bfs);
    return 0;
}