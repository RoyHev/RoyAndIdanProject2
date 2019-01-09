//
// Created by roy on 06/01/19.
//

#ifndef ROYANDIDANPROJECT2_FILECACHEMANAGER_H
#define ROYANDIDANPROJECT2_FILECACHEMANAGER_H


#include "CacheManager.h"
#include <map>
#include <string>

class FileCacheManager : public CacheManager {
    std::map<std::string, std::string> cacheMap;
public:
    bool solutionExists(string problem) override;

    string getSolution(string problem) override;

    void saveSolution(string problem, string solution) override;

};


#endif //ROYANDIDANPROJECT2_FILECACHEMANAGER_H
