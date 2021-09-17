#include "game.h"

bool Game::Init()
{
    PlayerData temp;
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
        server.recieve(ipToSendTo, &temp);
        std::cout << "Recieve Loop" << std::endl;
        if (&temp != nullptr)
        {
            Fill(temp);
        }
    }
    return true;
}

void Game::Fill(PlayerData toFill)
{
        int team = 0;
        std::cout << "Fill in name for player " << toFill.id << " : ";
        std::cin >> toFill.name;

        std::cout << "What Team: ";
        std::cin >> team;
        toFill.team = (Team)team;
        players.push_back(toFill);
        server.sendBytes(toFill, sizeof(toFill), "192.168.1.1", 1025);
        currentLobby += 1;
}

void Game::Update()
{
    // Check current state of players in here. Have they been shot? Have they been the shooter?
    for(auto p : players)
    {
        
    }

}