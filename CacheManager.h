//
// Created by roy on 06/01/19.
//

#ifndef ROYANDIDANPROJECT2_CACHEMANAGER_H
#define ROYANDIDANPROJECT2_CACHEMANAGER_H

class CacheManager{
public:
    //TODO - change to proper classes for each functions.
    virtual bool solutionExists(int problem) = 0;
    virtual int getSolution(int problem) = 0;
    //TODO - is it supposed to get a problem and a solution and save or get
    // only a problem ?
    virtual void saveSolution(int problem, int solution) = 0;

};

#endif //ROYANDIDANPROJECT2_CACHEMANAGER_H
