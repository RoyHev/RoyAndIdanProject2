//
// Created by roy on 08/01/19.
//

#ifndef ROYANDIDANPROJECT2_BREADTHFIRSTSEARCH_H
#define ROYANDIDANPROJECT2_BREADTHFIRSTSEARCH_H

#include "Searcher.h"
#include <queue>

template<class T>
class BreadthFirstSearch : public Searcher<T> {
public:
    vector<State<T>> search(Searchable<T> *searchable) override {
        vector<State<T>> path;
        State<T> currentState = searchable->getInitialState();
        State<T> goalState = searchable->getGoalState();
        queue<State<T>> stateQ;
        currentState.setVisited(true);
        currentState.setCameFrom(nullptr);
        stateQ.push_back(currentState);
        while (!stateQ.empty()) {
            currentState = stateQ.front();
            if (currentState == goalState) {
                while (!(currentState == goalState)) {
                    currentState = currentState.getCameFrom();
                    path.insert(path.begin(), currentState);
                }
                return path;
            }
            stateQ.pop_front();
            for (State<T> adj : searchable->getPossibleStates(currentState)) {
                if (adj.getVisited()) {
                    continue;
                }
                adj.setVisited(true);
                adj.setCameFrom(&currentState);
                stateQ.push_back(adj);
            }
        }
        //could not find path from requested initial to goal.
        return nullptr;

    }

};


#endif //ROYANDIDANPROJECT2_BREADTHFIRSTSEARCH_H
