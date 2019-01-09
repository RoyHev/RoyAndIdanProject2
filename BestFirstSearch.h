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
    bool alreadyVisited(priority_queue <State<T>*> openQ, State<T>* curState){
        bool wasVisited = false;
        while(!openQ.empty()){
            if (openQ.top()->equalsTo(curState)){
                wasVisited = true;
                break;
            }
            openQ.pop();
        }
        return wasVisited;
    }

    vector<State<T>*> search(Searchable<T> *searchable) override {
        vector<State<T> *> nodesVisited;
        vector<State<T>*> tempVec;
        unordered_set<State<T>*> unorderedSetClose;
        priority_queue<State<T>*> priorityQueueOpen;
        vector<State<T>*> path;
        State<T> *currentState = searchable->getInitialState();
        currentState->setCameFrom(currentState);
        priorityQueueOpen.push(currentState);
        nodesVisited.emplace_back(currentState);
        while (!priorityQueueOpen.empty()) {
            currentState = priorityQueueOpen.top();
            priorityQueueOpen.pop();
            unorderedSetClose.insert(currentState);
            if (currentState == searchable->getGoalState()){
                while (!currentState->equalsTo(searchable->getInitialState())){
                    currentState = currentState->getCameFrom();
                    path.insert(path.begin(), currentState);
                }
                return path;

            } else {
                for (State<T>* adj : searchable->getPossibleStates(currentState)){
                    if (!alreadyVisited(priorityQueueOpen,adj) &&
                    unorderedSetClose.count(adj) != 0){
                        adj->setCameFrom(currentState);
                        priorityQueueOpen.push(adj);
                    }
                }
            }
        }
        //could not find path from requested initial to goal.
        return tempVec;
    }
};

#endif //ROYANDIDANPROJECT2_BESTFIRSTSEARCH_H
