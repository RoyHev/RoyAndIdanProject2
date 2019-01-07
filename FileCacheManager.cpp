//
// Created by roy on 06/01/19.
//

#include "FileCacheManager.h"

template<class P>
bool FileCacheManager::solutionExists(P problem) {
    if (this->cacheMap.find(problem) != cacheMap.end()) {
        return true;
    }
    return false;
}

template<class P, class S>
S FileCacheManager::getSolution(P problem) {
    if (solutionExists(problem)) {
        return cacheMap.find(problem)->second;
    }
    throw std::runtime_error("couldn't find solution for this problem");
}

template<class P, class S>
void FileCacheManager::saveSolution(P problem, S solution) {
    //TODO - what to do if the given problem is already exists?
    if (!solutionExists(problem)) {
        this->cacheMap.insert(std::make_pair(problem, solution));
    }
}
