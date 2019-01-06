//
// Created by roy on 06/01/19.
//

#ifndef ROYANDIDANPROJECT2_MYTESTCLIENTHANDLER_H
#define ROYANDIDANPROJECT2_MYTESTCLIENTHANDLER_H


#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"

class MyTestClientHandler : public ClientHandler{
    Solver solver;
    CacheManager* cacheManager;
public:

};


#endif //ROYANDIDANPROJECT2_MYTESTCLIENTHANDLER_H
