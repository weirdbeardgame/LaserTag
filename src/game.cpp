#include "game.h"

bool Game::Init()
{
    // Establish server and game rules in here. Add players...
    server.open("192.168.1.1", 88, IPPROTO_UDP, SOCK_DGRAM );
    server.sendBytes("Hello There", 15);

    return true;
}


void Game::Update()
{

  std::cout << server.recieve() << std::endl;



/*for(auto p : players)
    {
        
    }*/

}