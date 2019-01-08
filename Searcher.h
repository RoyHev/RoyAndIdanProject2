//
// Created by roy on 08/01/19.
//

#ifndef ROYANDIDANPROJECT2_SEARCHER_H
#define ROYANDIDANPROJECT2_SEARCHER_H

#include <vector>
#include "Searchable.h"

template<class T>
class Searcher {

public:
    virtual std::vector<T> search(Searchable<T> *searchable) = 0;

};

#endif //ROYANDIDANPROJECT2_SEARCHER_H
