//
// Created by roy on 06/01/19.
//

#ifndef ROYANDIDANPROJECT2_MYTESTCLIENTHANDLER_H
#define ROYANDIDANPROJECT2_MYTESTCLIENTHANDLER_H


#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"


//TODO - check if we need this class.
template <class P, class S>
class MyTestClientHandler : public ClientHandler{
    Solver<P,S> solver;
    CacheManager<P,S>* cacheManager;
public:

};


#endif //ROYANDIDANPROJECT2_MYTESTCLIENTHANDLER_H
