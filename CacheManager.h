//
// Created by roy on 06/01/19.
//

#ifndef ROYANDIDANPROJECT2_CACHEMANAGER_H
#define ROYANDIDANPROJECT2_CACHEMANAGER_H

template <class P, class S>
class gCacheManager{
public:
    virtual bool solutionExists(P problem) = 0;
    virtual S getSolution(P problem) = 0;
    virtual void saveSolution(P problem, S solution) = 0;

};

#endif //ROYANDIDANPROJECT2_CACHEMANAGER_H
