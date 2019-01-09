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

int main() {
    vector<vector<double>> vec;
    double num = 1;
    for (int i = 0; i<4; i++){
        vector<double> tempVec;
        for (int j=0; j<4; j++){
            tempVec.push_back(num);
            num++;
        }
        vec.push_back(tempVec);
    }
    Point p1(1,1);
    Point p2(3,2);
////
//    Searchable<Point>* searchable = new Matrix(p1,p2,vec);
    Searchable<Point> *s = new Matrix(p1, p2, vec);
    Searcher<Point> *searcher = new DepthFirstSearch<Point>();
    vector<State<Point>> solution;
    solution = searcher->search(s);

    return 0;
}