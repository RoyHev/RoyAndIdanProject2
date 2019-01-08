//
// Created by idantp on 1/9/19.
//

#ifndef ROYANDIDANPROJECT2_DEPTHFIRSTSEARCH_H
#define ROYANDIDANPROJECT2_DEPTHFIRSTSEARCH_H

#include "Searcher.h"
#include <stack>

template <class T>
class DepthFirstSearch : public Searcher<T> {
public:
    vector<State<T>> search(Searchable<T> *searchable) override {
        stack<State<T>> stateStack;
        State<T> currentState = searchable->getInitialState();
        currentState.setCameFrom(nullptr);
        stateStack.push(currentState);
        while (!stateStack.empty()){

            currentState = stateStack.top();
            stateStack.pop();

        }


    }
};


#endif //ROYANDIDANPROJECT2_DEPTHFIRSTSEARCH_H
