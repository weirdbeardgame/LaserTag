#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <netinet/in.h>


// Need to draft a welcome packet that accepts all connections as long as not full lobby or game started

enum Team {RED, BLUE, PURPLE, PINK};
enum State {ALIVE, DEAD};

/*********************************************************************************************************************************
* The General Idea behind this is that there's some kind of console or gui interface that allows the game master.
* to enter data for each player and send it out assuming the player's actually attempting to connect
* So order of operations in a basic form is. Game Master fills out form for each player in a json or some other format. 
* Or it's not serialized and that data only exists per session. Either way it's entered and saved in system.
* Player suit sends out hello packet with ID, laser frequency and sensor capabilities? Probably for debug mode at least
* Server responds back with a welcome packet that contains string name of player. Color and associated team if team battle mode.
* Score counter zeroed out. Status of game room and lobby. Game mode if suit needs to be aware for some reason. 
* Server sends out packet to start once timer for lobby or start game has been initiated
*********************************************************************************************************************************/

// The packed data
struct PlayerData
{
    int id;
    int score;

    std::string name;

    // Representing laser frequency. Suits detect frequency of he who shot to report it to server. I was shot by player X!
    float frequency = 0;

    Team team;
    State state;
};

class Player
{
private:

PlayerData data;
sockaddr_in ipToSendTo;

// The potential variable for registering hit or shooter based on frequency of infared
// int ledFrequency = 0;

public:
// Thing about this is. This should be handled by client? 
// Client sends hello packet out to server. Server adds client to struct like vector 
bool Init(PlayerData data);
// To check state
void Update();
};

#endif