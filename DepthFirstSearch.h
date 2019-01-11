//
// Created by idantp on 1/9/19.
//

#ifndef ROYANDIDANPROJECT2_DEPTHFIRSTSEARCH_H
#define ROYANDIDANPROJECT2_DEPTHFIRSTSEARCH_H

#include "Searcher.h"
#include <stack>

template<class T>
class DepthFirstSearch : public Searcher<T> {
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
        stack<State<T> *> stateStack;
        vector<State<T> *> path;
        State<T> *currentState = searchable->getInitialState();
        currentState->setCameFrom(currentState);
        nodesVisited.emplace_back(currentState);
        stateStack.push(currentState);
        //go over the stack of states.
        while (!stateStack.empty()) {
            currentState = stateStack.top();
            stateStack.pop();
            if (currentState->equalsTo(searchable->getGoalState())) {
                path.insert(path.begin(), currentState);
                //restore the path and return it.
                while (!(currentState->equalsTo(
                        searchable->getInitialState()))) {
                    currentState = currentState->getCameFrom();
                    path.insert(path.begin(), currentState);
                }
                return path;
            }
            //if it wasn't visited, mark it as visited.
            if (!hasNodeBeenVisited(nodesVisited, currentState)) {
                nodesVisited.emplace_back(currentState);
            }
            //go over all the neighbors of this specific node.
            for (State<T> *adj : searchable->getPossibleStates(currentState)) {
                //already visited, move on to next iteration.
                if (hasNodeBeenVisited(nodesVisited, adj)) {
                    continue;
                }
                nodesVisited.emplace_back(adj);
                adj->setCameFrom(currentState);
                stateStack.push(adj);
            }
        }
        //could not find path from requested initial to goal.
        return tempVec;
    }
};


#endif //ROYANDIDANPROJECT2_DEPTHFIRSTSEARCH_H
