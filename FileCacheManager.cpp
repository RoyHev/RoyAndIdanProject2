//
// Created by roy on 06/01/19.
//

#include "FileCacheManager.h"

bool FileCacheManager::solutionExists(string problem) {
    if (this->cacheMap.find(problem) == cacheMap.end()){
        return false;
    } else {
        return true;
    }
}

string FileCacheManager::getSolution(string problem) {
    if (solutionExists(problem)){
        return cacheMap.find(problem)->second;
    } else {
        perror("No solution for given Problem.");
    }
}

void FileCacheManager::saveSolution(string problem, string solution) {
    this->cacheMap.insert(make_pair(problem,solution));
}
