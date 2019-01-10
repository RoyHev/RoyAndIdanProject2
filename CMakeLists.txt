cmake_minimum_required(VERSION 3.13)
project(RoyAndIdanProject2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(RoyAndIdanProject2 main.cpp Server.cpp Server.h MySerialServer.cpp MySerialServer.h ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h Solver.h CacheManager.h FileCacheManager.cpp FileCacheManager.h State.cpp State.h Point.cpp Point.h Searchable.h Matrix.cpp Matrix.h Searcher.h SolverSearcher.cpp SolverSearcher.h BreadthFirstSearch.cpp BreadthFirstSearch.h BestFirstSearch.cpp BestFirstSearch.h AStar.cpp AStar.h DepthFirstSearch.cpp DepthFirstSearch.h ParallelServer.cpp ParallelServer.h)