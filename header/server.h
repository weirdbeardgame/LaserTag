#ifndef SERVER_H
#define SERVER_H
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <stdio.h>
#include <netdb.h>
#include <vector>

#include "player.h"

class Server
{
    private:
    int sock;
    sockaddr_in sockOut;
    hostent *host;
    addrinfo info, *infoP;
    timeval tv;
    fd_set set;

    public:
    bool open(const char* hostName, uint16_t port, int protocol, int sockType);
    int recieve(sockaddr_in& sockIn, PlayerData* buff);
    template<typename T>
    int sendBytes(T val, int siz, const char* ip, uint16_t port)
    {
        if (sock <= 0)
        {
            std::cerr << "Connection terminated" << std::endl;
            return -1;
        }

        sockOut.sin_family = AF_INET;
        sockOut.sin_addr.s_addr = inet_addr(ip);
        sockOut.sin_port = port;

        char* buffer = (char*)&val;

        int size = sendto(sock, buffer, siz, 0, (const sockaddr *)&sockOut, (socklen_t)sizeof(sockOut));
        if (size < 0)
        {
            //std::cerr << "Send Err: " << strerror(errno) << std::endl;
            return false;
        }
        return size;
    }
};
#endif