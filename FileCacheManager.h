//
// Created by roy on 06/01/19.
//

#ifndef ROYANDIDANPROJECT2_FILECACHEMANAGER_H
#define ROYANDIDANPROJECT2_FILECACHEMANAGER_H


#include "CacheManager.h"
#include <map>

class FileCacheManager : public CacheManager<class P, class S> {
    std::map<S, P> cacheMap;
public:
    template<class P>
    bool solutionExists(P problem);

    template<class P, class S>
    S getSolution(P problem);

    template<class P, class S>
    void saveSolution(P problem, S solution);

};


#endif //ROYANDIDANPROJECT2_FILECACHEMANAGER_H
