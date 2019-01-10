//
// Created by roy on 08/01/19.
//

#ifndef ROYANDIDANPROJECT2_BESTFIRSTSEARCH_H
#define ROYANDIDANPROJECT2_BESTFIRSTSEARCH_H

#include <queue>
#include <unordered_set>
#include "Searcher.h"

template<class T>
class BestFirstSearch : public Searcher<T> {
public:
    bool hasNodeBeenVisited(vector<State<T> *> nodesVec, State<T> *node) {
        for (State<T> *state : nodesVec) {
            if (state->equalsTo(node)) {
                return true;
            }
        }
        return false;
    }

    vector<State<T>*> search(Searchable<T> *searchable) override {
        vector<State<T> *> nodesVisited;
        vector<State<T>*> tempVec;
        vector<State<T>*> vectorPath;

        priority_queue<State<T>*,vector<State<T>*>,greater<State<T>*>> priorityQueueOpen;

        vector<State<T>*> path;
        State<T> *currentState = searchable->getInitialState();
        currentState->setCameFrom(currentState);
        priorityQueueOpen.push(currentState);
        while (!priorityQueueOpen.empty()) {
            currentState = priorityQueueOpen.top();
            priorityQueueOpen.pop();
            if (currentState == searchable->getGoalState()){
                vectorPath.push_back(currentState);
                return vectorPath;

            } else {
                for (State<T>* adj : searchable->getPossibleStates(currentState)){
                    if (hasNodeBeenVisited(nodesVisited, adj)) {
                        continue;
                    }
                    else{
                        adj->setCameFrom(currentState);
                        priorityQueueOpen.push(adj);
                    }
                }
                nodesVisited.emplace_back(currentState);
                vectorPath.push_back(currentState);
            }
        }
        //could not find path from requested initial to goal.
        return tempVec;
    }
};

#endif //ROYANDIDANPROJECT2_BESTFIRSTSEARCH_H
