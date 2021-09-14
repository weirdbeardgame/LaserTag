#include "server.h"
#include <errno.h>
#include <string.h>
#include <unistd.h>

// hostname and port could be to pass the server addres and port to broadcast on.
// For now only port is used and server ip i'm assuming is what's being broadcast on.
bool Server::open(const char* hostname, uint16_t port, int protocol, int sockType)
{
    info.ai_family = AF_INET;
    info.ai_flags = AI_PASSIVE;
    info.ai_socktype = sockType;
    info.ai_protocol = protocol;

    sock = socket(info.ai_family, info.ai_socktype, info.ai_protocol);

    if (sock < 0)
    {
        std::cerr << "SOCKET ERROR: " << strerror(errno) << std::endl;
        return false;
    }

    sockOut.sin_family = AF_INET;
    sockOut.sin_addr.s_addr = INADDR_ANY;
    sockOut.sin_port = port;

    int conErr = bind(sock, (const sockaddr *)&sockOut, sizeof(sockaddr_storage));

    if (conErr != 0)
    {
        std::cerr << "SERVER ERROR: " << strerror(errno) << std::endl;
        return false;
    }

    return true;
}

// Mistake number one in this case. I didn't fill the IP in for SendTO from here. This is not supposed to be the initator. This is the reciever.
// The client is the one whom initiates!

int Server::recieve(sockaddr_in& sockIn, PlayerData* buff)
{
    int i, buffSize = 512;

    socklen_t size = sizeof(sockIn);

    // This is definitely working. It only errs out on call from client.
    i = recvfrom(sock, buff, buffSize, 0, (struct sockaddr*)&sockIn, &size); 

    if (i < 0)
    {
        std::cerr << "Recieve Err: " << gai_strerror(i) << std::endl;
        return i;
    }
    if (buffSize < i)
    {
        buffSize = i;
    }

    return i;
}