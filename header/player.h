#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>

enum Team {RED, BLUE, PURPLE, PINK};
enum State {ALIVE, DEAD};

class Player
{
private:

int id;
int score;

Team team;
State state;

std::string name;
public:

// Thing about this is. This should be handled by client? 
// Client sends hello packet out to server. Server adds client to struct like vector 
bool Init();
// To check state
void Update();

};

#endif