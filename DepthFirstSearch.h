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
    vector<State<T>> search(Searchable<T> *searchable) override {
        stack<State<T>> stateStack;
        vector<State<T>> path;
        State<T> currentState = searchable->getInitialState();
        currentState.setCameFrom(nullptr);
        stateStack.push(currentState);
        //go over the stack of states.
        while (!stateStack.empty()) {
            currentState = stateStack.top();
            stateStack.pop();
            if (currentState == searchable->getGoalState()) {
                //restore the path and return it.
                while (!(currentState == searchable->getInitialState())) {
                    currentState = currentState.getCameFrom();
                    path.insert(path.begin(), currentState);
                }
                return path;
            }
            //if it wasn't visited, mark it as visited.
            if (currentState.getVisited() == false) {
                currentState.setVisited(true);
            }
            //go over all the neighbors of this specific node.
            for (State<T> adj : searchable->getPossibleStates(currentState)) {
                //already visited, move on to next iteration.
                if (adj.getVisited()) {
                    continue;
                }
                adj.setVisited(true);
                adj.setCameFrom(&currentState);
                stateStack.push(adj);
            }

        }
        //could not find path from requested initial to goal.
        return nullptr;

    }
};


#endif //ROYANDIDANPROJECT2_DEPTHFIRSTSEARCH_H
