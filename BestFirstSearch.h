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
    bool alreadyVisited(priority_queue <State<T>> openQ, State<T> curState){
        bool wasVisited = false;
        while(!openQ.empty()){
            if (openQ.top().equalsTo(curState)){
                wasVisited = true;
                break;
            }
            openQ.pop();
        }
        return wasVisited;
    }

    vector<State<T>> search(Searchable<T> *searchable) override {
        unordered_set<State<T>> unorderedSetClose;
        priority_queue<State<T>> priorityQueueOpen;
        vector<State<T>> path;
        priorityQueueOpen.push(searchable->getInitialState());
        while (!priorityQueueOpen.empty()) {
            State<T> temp = priorityQueueOpen.top();
            priorityQueueOpen.pop();
            unorderedSetClose.insert(temp);
            if (temp == searchable->getGoalState()){
                while (!temp.equalsTo(searchable->getInitialState())){
                    temp = *temp.getCameFrom();
                    path.insert(path.begin(), temp);
                }
                return path;

            } else {
                for (State<T> search : searchable->getPossibleStates(temp)){
                    if (!alreadyVisited(priorityQueueOpen,search) &&
                    unorderedSetClose.count(search) != 0){
                        search.setCameFrom(&temp);
                        priorityQueueOpen.push(search);
                    }
                }
            }
        }
        //could not find path from requested initial to goal.
        return vector<State<T>>();
    }
};

#endif //ROYANDIDANPROJECT2_BESTFIRSTSEARCH_H
