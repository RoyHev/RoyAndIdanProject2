//
// Created by roy on 08/01/19.
//

#ifndef ROYANDIDANPROJECT2_BREADTHFIRSTSEARCH_H
#define ROYANDIDANPROJECT2_BREADTHFIRSTSEARCH_H

#include "Searcher.h"
#include <queue>
#include <iostream>

template<class T>
class BreadthFirstSearch : public Searcher<T> {
public:

    bool hasNodeBeenVisited(vector<State<T> *> nodesVec, State<T> *node) {
        for (State<T> *state : nodesVec) {
            if (state->equalsTo(node)) {
                return true;
            }
        }
        return false;
    }

    vector<State<T> *> search(Searchable<T> *searchable) override {
        vector<State<T> *> nodesVisited;
        vector<State<T> *> tempVec;
        vector<State<T> *> path;
        State<T> *currentState = searchable->getInitialState();
        currentState->setCameFrom(currentState);
        nodesVisited.emplace_back(currentState);
        State<T> *goalState = searchable->getGoalState();
        queue<State<T> *> stateQ;
        stateQ.push(currentState);
        while (!stateQ.empty()) {

            currentState = stateQ.front();
            if (currentState->equalsTo(goalState)) {
                path.insert(path.begin(), currentState);
                while (!(currentState->equalsTo(
                        searchable->getInitialState()))) {
                    currentState = currentState->getCameFrom();
                    path.insert(path.begin(), currentState);
                }
                return path;
            }
            stateQ.pop();
            for (State<T> *adj : searchable->getPossibleStates(currentState)) {
                if (hasNodeBeenVisited(nodesVisited, adj)) {
                    continue;
                }
                nodesVisited.emplace_back(adj);
                adj->setCameFrom(currentState);
                stateQ.push(adj);
            }
        }
        //could not find path from requested initial to goal.
        return tempVec;

    }

};


#endif //ROYANDIDANPROJECT2_BREADTHFIRSTSEARCH_H
