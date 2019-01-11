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
    State<Point>* s1 = new State<Point>(Point(0,0),3);
    State<Point>* s2 = new State<Point>(Point(0,1),1);
    State<Point>* s3 = new State<Point>(Point(0,2),2);
    State<Point>* s4 = new State<Point>(Point(1,0),9);
    State<Point>* s5 = new State<Point>(Point(1,1),15);
    State<Point>* s6 = new State<Point>(Point(1,2),11);
    State<Point>* s7 = new State<Point>(Point(2,0),7);
    State<Point>* s8 = new State<Point>(Point(2,1),1);
    State<Point>* s9 = new State<Point>(Point(2,2),9);
    vector<State<Point>*> v1 = {s1,s2,s3};
    vector<State<Point>*> v2 = {s4,s5,s6};
    vector<State<Point>*> v3 = {s7,s8,s9};
    vec.emplace_back(v1);
    vec.emplace_back(v2);
    vec.emplace_back(v3);
//    double num = 1;
//    for (int i = 0; i < 3; i++) {
//        vector<State<Point> *> tempVec;
//        for (int j = 0; j < 3; j++) {
//            State<Point> *state = new State<Point>(Point(i, j));
//            state->setCost(num);
//            tempVec.push_back(state);
//            num++;
//        }
//        vec.push_back(tempVec);
//    }
    Point p1(0, 0);
    Point p2(2, 2);
    Searchable<Point> *s = new Matrix(p1, p2, vec);
    //Searcher<Point> *searcher = new DepthFirstSearch<Point>();
    vector<State<Point> *> solution;
    //solution = searcher->search(s);

    Searcher<Point> *searcherBest = new BestFirstSearch<Point>();
    solution = searcherBest->search(s);
    return 0;
}