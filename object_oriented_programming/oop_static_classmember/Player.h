#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player
{
private:
    static int num_players; //can't be initialized here
    std::string name;
    int health;
    int xp;
public:
    //member methods
    std::string get_name(){return name;}
    int get_health(){return health;}
    int get_xp(){return xp;}
    //constructor
    Player(std::string name_val="none", int health_val = 0, int xp_val = 0);
    //copy constructor
    Player(const Player &source);
    //destructor
    ~Player();
    
    static int get_num_players (); //only has access to static variable

};

#endif // PLAYER_H
