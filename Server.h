//
// Created by roy on 06/01/19.
//

#ifndef ROYANDIDANPROJECT2_SERVER_H
#define ROYANDIDANPROJECT2_SERVER_H


namespace server_side {
    class Server {
    public:
        virtual void open(int portNum) = 0;
        virtual void close() = 0;

    };
}

#endif //ROYANDIDANPROJECT2_SERVER_H
