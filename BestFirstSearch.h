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
    class StateCompare {
    public:
        bool operator()(State<T> *left, State<T> *right) {
            return (left->getPathCost() > right->getPathCost());
        }
    };

public:
    bool hasNodeBeenVisited(vector<State<T> *> nodesVec, State<T> *node) {
        for (State<T> *state : nodesVec) {
            if (state->equalsTo(node)) {
                return true;
            }
        }
        return false;
    }

    bool isNodeInQueue(
            priority_queue<State<T> *, vector<State<T> *>, StateCompare> priorityQueue,
            State<T> *node) {
        while (!priorityQueue.empty()) {
            if (node->equalsTo(priorityQueue.top())) {
                return true;
            }
            priorityQueue.pop();
        }
        return false;
    }


    vector<State<T> *> search(Searchable<T> *searchable) override {
        //keeps the nodes we've already traveled in
        vector<State<T> *> nodesVisited;
        //keeps the nodes we need to travel in. sorts the nodes from the ones with the lowest path-cost to the highest
        // one
        priority_queue<State<T> *, vector<State<T> *>, StateCompare>open;
        //the final path from the source node to the destination node
        vector<State<T> *> path;
        State<T> *currentState = searchable->getInitialState();
        currentState->setCameFrom(currentState);
        currentState->setPathCost(currentState->getCost());
        open.push(currentState);
        while (!open.empty()) {
            currentState = open.top();
            open.pop();
            //if the are no more paths to check to the destination node then return the path to it
            if (currentState->equalsTo(searchable->getGoalState())) {
                nodesVisited.push_back(currentState);
                path.insert(path.begin(), currentState);
                while (!(currentState->equalsTo(
                        searchable->getInitialState()))) {
                    currentState = currentState->getCameFrom();
                    path.insert(path.begin(), currentState);
                }
                return path;
            } else {
                //find all the adjacent nodes
                for (State<T> *adj : searchable->getPossibleStates(currentState)) {
                    //gets the current adjacent State
                    double adjPathCost = currentState->getPathCost()+adj->getCost();
                    /*
                     * if the node was already visited and we dont need to find a cheaper way to it - continue,
                     * but if the node was already visited and we can to find a cheaper way to it - check
                     */
                    if (hasNodeBeenVisited(nodesVisited, adj) ||
                        isNodeInQueue(open, adj)) {
                        if (!hasNodeBeenVisited(nodesVisited, adj)
                        &&isNodeInQueue(open, adj)) {
                            //compares the lowest cost of the same State with 2 different paths to it.
                            if (adjPathCost < adj->getPathCost()) {
                                //if cheaper path found - update it
                                adj->setCameFrom(currentState);
                                adj->setPathCost(adjPathCost);
                                open.emplace(adj);
                            }
                        }
                        continue;
                    } else {
                        //for a node we visit in the first time - update its information.
                        adj->setPathCost(adjPathCost);
                        adj->setCameFrom(currentState);
                        open.emplace(adj);
                    }
                }
                //insert the current node to nodesVisited to make sure we dont check it again
                nodesVisited.emplace_back(currentState);
            }
        }
        //could not find path from requested initial to goal.
        return path;
    }
};

#endif //ROYANDIDANPROJECT2_BESTFIRSTSEARCH_H
