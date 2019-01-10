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

    bool isNodeInQueue(priority_queue<State<T> *, vector<State<T> *>,
            greater<State<T> *>> priorityQueue, State<T> *node) {
        while (!priorityQueue.empty()) {
            if (node->equalsTo(priorityQueue.top())) {
                return true;
            }
            priorityQueue.pop();
        }
        return false;
    }

    vector<State<T> *> search(Searchable<T> *searchable) override {
        vector<State<T> *> nodesVisited;
        vector<State<T> *> tempVec;
        vector<State<T> *> vectorPath;
        unordered_set<State<T> *> pathSet;

        priority_queue<State<T> *, vector<State<T> *>, greater<State<T> *>> priorityQueueOpen;

        vector<State<T> *> path;
        State<T> *currentState = searchable->getInitialState();
        currentState->setCameFrom(currentState);
        priorityQueueOpen.push(currentState);
        while (!priorityQueueOpen.empty()) {
            currentState = priorityQueueOpen.top();
            priorityQueueOpen.pop();
            if (currentState->equalsTo(searchable->getGoalState())) {
                vectorPath.push_back(currentState);
                //TODO return

            } else {
                for (State<T> *adj : searchable->getPossibleStates(
                        currentState)) {
                    if (hasNodeBeenVisited(nodesVisited, adj) ||
                        isNodeInQueue(priorityQueueOpen, adj)) {
                        continue;
                    } else {
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
