//
// Created by roy on 06/01/19.
//

#ifndef ROYANDIDANPROJECT2_CACHEMANAGER_H
#define ROYANDIDANPROJECT2_CACHEMANAGER_H

#include <string>

using namespace std;

class CacheManager{
public:
    virtual bool solutionExists(string problem) = 0;
    virtual string getSolution(string problem) = 0;
    virtual void saveSolution(string problem, string solution) = 0;

};

#endif //ROYANDIDANPROJECT2_CACHEMANAGER_H
