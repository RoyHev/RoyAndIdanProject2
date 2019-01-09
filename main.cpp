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

int main() {
    vector<vector<State<Point> *>> vec;
    double num = 1;
    for (int i = 0; i < 3; i++) {
        vector<State<Point> *> tempVec;
        for (int j = 0; j < 3; j++) {
            State<Point> *state = new State<Point>(Point(i, j));
            state->setCost(num);
            tempVec.push_back(state);
            num++;
        }
        vec.push_back(tempVec);
    }
    Point p1(0, 0);
    Point p2(2, 2);
    Searchable<Point> *s = new Matrix(p1, p2, vec);
    Searcher<Point> *searcher = new DepthFirstSearch<Point>();
    vector<State<Point> *> solution;
    solution = searcher->search(s);
    return 0;
}