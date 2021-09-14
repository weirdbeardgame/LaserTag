#ifndef GAME_H
#define GAME_H

#include <vector>
#include <map>
#include <iostream>

#include "player.h"
#include "server.h"

class Game
{
private:
Server server;

sockaddr_in ipToSendTo;

std::vector<Player> players; // The magic
//std::map<Player, Team> teamPlayers; // A concept for team inclusion

int currentLobby;
int maxPlayers = 5;

public:
bool Init();
// Check state and update score and other game data accordingly
void Update();

};

#endif