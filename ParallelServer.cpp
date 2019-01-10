//
// Created by idantp on 1/10/19.
//
#include <netinet/in.h>
#include <thread>
#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <unistd.h>
#include <thread>
#include <iostream>
#include "ParallelServer.h"

using namespace std;
using namespace std::chrono;
using namespace std::chrono::_V2;

void server_side::ParallelServer::open(int portNum, ClientHandler &clientHandler) {
    int serverSockFD;
    //initialize the sockets variables
    struct sockaddr_in serv_addr;

    //First call to socket() function
    serverSockFD = socket(AF_INET, SOCK_STREAM, 0);

    if (serverSockFD < 0) {
        perror("ERROR Could Not Open Socket.");
        exit(1);
    }

    // Initialize socket structure
    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portNum);


    /* Now bind the host address using bind() call.*/
    if (bind(serverSockFD, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */

    listen(serverSockFD, 5);
    this->sockfd = serverSockFD;
    start(serverSockFD,clientHandler);

}

void server_side::ParallelServer::stop() {
    if (sockfd != -1){
        close(sockfd);
    }

}

void server_side::ParallelServer::start(int serverSocket,
                                        ClientHandler &clientHandler) {
    int newsockfd;
    int clilen;
    struct sockaddr_in cli_addr;
    clilen = sizeof(cli_addr);

    while (true) {


        /* Accept actual connection from the client */
        newsockfd = accept(serverSocket, (struct sockaddr *) &cli_addr,
                (socklen_t *) &clilen);

        if (newsockfd < 0) {
            perror("ERROR Could Not Accept From Socket");
            exit(1);
        }

        handle(newsockfd,clientHandler);
    }

}

static void handleSpecificClient(int clientSocket, ClientHandler *clientHandler){
    clientHandler->handleClient(clientSocket);
}

void server_side::ParallelServer::handle(int clientSocket,
                                          ClientHandler &clientHandler) {

    std::thread thread(handleSpecificClient,clientSocket,&clientHandler);
    thread.detach();

}

//TODO - check timed out if needed.