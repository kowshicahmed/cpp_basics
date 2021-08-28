#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player
{
private: //by default a class is private
    //attributes
    std::string name;
    int health;
    int xp;
public:
    //methods
    
    
    //overloaded constructors
    Player ();
    Player (std::string name_val);
    Player (std::string name_val, int health_val, int xp_val);
};



int main(int argc, char **argv)
{
	Player empty;
    Player frank {"Frank"};
    Player villain {"Villain", 100, 55};
	return 0;
}

Player::Player ()
    :name{"None"}, health{0}, xp{0}
{
        
}

Player::Player(std::string name_val)
    :name {name_val}, health{0}, xp{0}
{
    
}
    
Player::Player (std::string name_val, int health_val, int xp_val)
    :name{name_val}, health{health_val}, xp{xp_val}
{
        
}