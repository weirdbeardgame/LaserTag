#include "game.h"

bool Game::Init()
{
    PlayerData* temp = new PlayerData();
    // Establish server and game rules in here. Add players...
    if (!server.open("192.168.1.1", 1025, IPPROTO_UDP, SOCK_DGRAM ))
    {
        std::cerr << "Server open error" << std::endl;
        return false;
    }

    while(currentLobby < 1)
    {
        // Using this to listen for hello packets.
        // Always remeber. Hello packets are just player data not initallized that do contain an ID for the server to respond to.
        if (server.recieve(ipToSendTo, temp) < 0)
        {
            std::cerr << "Recieve err" << std::endl;
        }

        std::cout << "Recieve Loop" << std::endl;
        if (temp != nullptr)
        {
            Fill(temp);
        }
    }
    delete(temp);
    return true;
}

void Game::Fill(PlayerData* toFill)
{
        int team = 0;
        std::cout << "Fill in name for player " << toFill->id << " : ";
        std::cin >> toFill->name;

        std::cout << "What Team: ";
        std::cin >> team;
        toFill->team = (Team)team;

        // ISSUE: This is only happening once. UDP packets can and will drop
        // We need a is recieved response from Server and from Client alike
        if (server.sendBytes(toFill, "192.168.1.35", 1025) < 0)
        {
            std::cerr << "Send Error" << std::endl;
        }


        players.push_back(toFill);
        currentLobby += 1;
}

void Game::Update()
{
    // Check current state of players in here. Have they been shot? Have they been the shooter?
    for(auto p : players)
    {
        
    }

}