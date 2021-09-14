#include "game.h"

bool Game::Init()
{
    PlayerData *temp;
    // Establish server and game rules in here. Add players...
    if (!server.open("192.168.1.1", 1025, IPPROTO_UDP, SOCK_DGRAM ))
    {
        std::cerr << "Server open error" << std::endl;
        return false;
    }

    while(currentLobby < maxPlayers)
    {
        // Using this to listen for hello packets.
        // Always remeber. Hello packets are just player data not initallized that do contain an ID for the server to respond to.
        server.recieve(ipToSendTo, temp);
        if (temp != nullptr)
        {
            // Grab ID in here and go to init from prefilled form
        }
    }
}

void Game::Update()
{
    // Check current state of players in here. Have they been shot? Have they been the shooter?
    for(auto p : players)
    {
        
    }

}