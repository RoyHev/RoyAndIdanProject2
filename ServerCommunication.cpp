//
// Created by roy on 13/01/19.
//

#include <strings.h>
#include <cstring>
#include <sys/socket.h>
#include "ServerCommunication.h"
#include <stdlib.h>
#include <unistd.h>

#define SPACE ' '


void ServerCommunication::writeToServer(int socketNum, string info) {
    //TODO - delete if not needed (works properly).
//    char buffer[SIZE];
//    bzero(buffer, SIZE);
//    strcpy(buffer, info.c_str());
    /* Send message to the server */
//    ssize_t n = write(socketNum, buffer, strlen(buffer));
    ssize_t n = write(socketNum, info.c_str(), (info.size()));
    if (n < 0) {
        perror("Could not write to Server.");
        exit(1);
    }
}


vector<string> ServerCommunication::readFromServer(int socketNum) {
    vector<string> problemInfo;
    char c;
    string temp;

    while (temp != END_PROBLEM)
    {
        ssize_t n = read(socketNum, &c, READ_CHAR);
        if (n < 0) {
            perror("Could not read from Server.");
        }
        while(c != ENTER){
            if (c == SPACE){
                read(socketNum, &c, READ_CHAR);
                continue;
            }
            temp += c;
            read(socketNum, &c, READ_CHAR);
        }
        if (temp == END_PROBLEM){
            break;
        }
        problemInfo.push_back(temp);
        temp.erase();
    }
    return problemInfo;
}
