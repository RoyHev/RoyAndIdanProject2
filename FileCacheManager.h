//
// Created by roy on 06/01/19.
//

#ifndef ROYANDIDANPROJECT2_FILECACHEMANAGER_H
#define ROYANDIDANPROJECT2_FILECACHEMANAGER_H


#include "CacheManager.h"
#include <map>
#include <string>
#include <fstream>

#define PROB_SOL_DELIMITER '$'

template<class P, class S>
class FileCacheManager : public CacheManager<P, S> {
    string fileName;
    std::map<std::string, std::string> cacheMap;
public:
    FileCacheManager(const string &fileName) : fileName(fileName) {}

    bool solutionExists(P problem) override {
        if (this->cacheMap.find(problem) == cacheMap.end()) {
            return false;
        } else {
            return true;
        }
    }

    S getSolution(P problem) override {
        if (solutionExists(problem)) {
            return cacheMap.at(problem);
        } else {
            perror("No solution for given Problem.");
        }
    }

    void saveSolution(P problem, S solution) override {
        this->cacheMap.insert(make_pair(problem, solution));
    }

    /**
     * writes a pair (problem and its solution) to the cache text File.
     * @param problem describes problem
     * @param solution describes solution
     */
    void writeToFile(P problem, S solution) {
        ofstream ofstream;
        ofstream.open(fileName, ios::out | ios::app);
        if (ofstream.is_open()) {
            ofstream << (string) problem << PROB_SOL_DELIMITER << (string) solution << endl;
            ofstream.close();
        } else { perror("couldn't open cache File"); }
    }

    /**
     * loads all the problems and their solutions from cache text file to the map.
     */
    void loadFromFile() {
        ifstream ifstream;
        ifstream.open(fileName);
        if (ifstream.is_open()) {
            for (string probSolution; getline(ifstream, probSolution);) {
                string thisProblem = probSolution.substr(0, probSolution.find(PROB_SOL_DELIMITER));
                string thisSolution = probSolution.substr(
                        (probSolution.find(PROB_SOL_DELIMITER) + 1),
                        probSolution.size() -
                        (thisProblem.size() + 1));
                this->cacheMap.insert(make_pair(thisProblem, thisSolution));
            }
        } else { perror("couldn't open cache File"); }
    }
};


#endif //ROYANDIDANPROJECT2_FILECACHEMANAGER_H
