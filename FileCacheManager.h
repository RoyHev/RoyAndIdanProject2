//
// Created by roy on 06/01/19.
//

#ifndef ROYANDIDANPROJECT2_FILECACHEMANAGER_H
#define ROYANDIDANPROJECT2_FILECACHEMANAGER_H


#include "CacheManager.h"
#include <map>
#include <string>
#include <fstream>

template <class P, class S>
class FileCacheManager : public CacheManager<P, S> {
    string fileName;
    std::map<std::string, std::string> cacheMap;
public:
    FileCacheManager(const string &fileName) : fileName(fileName) {}

    bool solutionExists(P problem) override {
        if (this->cacheMap.find(problem) == cacheMap.end()){
            return false;
        } else {
            return true;
        }
    }

    S getSolution(P problem) override {
        if (solutionExists(problem)){
            return cacheMap.at(problem);
        } else {
            perror("No solution for given Problem.");
        }
    }

    void saveSolution(P problem, S solution) override {
        this->cacheMap.insert(make_pair(problem,solution));
    }

    void writeToFile(P problem,S solution){
        ofstream ofstream;
        ofstream.open(fileName, ios::out| ios::app);
        if (ofstream.is_open()){
            ofstream << (string)problem << "!?!?!?" << (string)solution<<endl;
            ofstream.close();
        }else { perror("couldn't open cache File");}
    }

};


#endif //ROYANDIDANPROJECT2_FILECACHEMANAGER_H
