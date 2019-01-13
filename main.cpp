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

int main() {


    vector<vector<State<Point> *>> vec;
    State<Point> *s1 = new State<Point>(Point(0, 0), 1);
    State<Point> *s2 = new State<Point>(Point(0, 1), 2);
    State<Point> *s3 = new State<Point>(Point(0, 2), 5);
    State<Point> *s4 = new State<Point>(Point(0, 3), 10);
    State<Point> *s5 = new State<Point>(Point(1, 0), 5);
    State<Point> *s6 = new State<Point>(Point(1, 1), 3);
    State<Point> *s7 = new State<Point>(Point(1, 2), 1);
    State<Point> *s8 = new State<Point>(Point(1, 3), -1);
    State<Point> *s9 = new State<Point>(Point(2, 0), 2);
    State<Point> *s10 = new State<Point>(Point(2, 1), 4);
    State<Point> *s11 = new State<Point>(Point(2, 2), 6);
    State<Point> *s12 = new State<Point>(Point(2, 3), 9);
    State<Point> *s13 = new State<Point>(Point(3, 0), 1);
    State<Point> *s14 = new State<Point>(Point(3, 1), 9);
    State<Point> *s15 = new State<Point>(Point(3, 2), 3);
    State<Point> *s16 = new State<Point>(Point(3, 3), 12);

//    vector<State<Point>*> v0 = {s1,s2,s3, s4};
//    vector<State<Point>*> v2 = {s5,s6,s7,s8};
//    vector<State<Point>*> v3 = {s9,s10,s11,s12};
//    vector<State<Point>*> v4 = {s13,s14,s15,s16};
//    vec.emplace_back(v1);
//    vec.emplace_back(v2);
//    vec.emplace_back(v3);
//    vec.emplace_back(v4);
//    Point p1(0, 0);
//    Point p2(3, 3);
//    Searchable<Point> *s = new Matrix(p1, p2, vec);
//    //Searcher<Point> *searcher = new DepthFirstSearch<Point>();
//    vector<State<Point> *> solution;
//    //solution = searcher->search(s);
//
//    Searcher<Point> *searcherBest = new BestFirstSearch<Point>();
//    solution = searcherBest->search(s);
    return 0;
}