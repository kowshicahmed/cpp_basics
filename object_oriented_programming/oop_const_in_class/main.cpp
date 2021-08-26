#include <iostream>

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
    void set_name (std::string name_val)
    {
        name = name_val;
    }
    
    std::string get_name () const //const correctness
    {
        return name;
    }
    
    //overloaded constructors
    
    Player ();
    Player (std::string name_val);
    Player (std::string name_val, int health_val, int xp_val);
};

void display_player_name (const Player &p);


int main(int argc, char **argv)
{
	const Player villain {"villain", 100, 55}; //canot change any of the attributes
	Player hero {"hero", 100, 15};
    display_player_name(villain);
    return 0;
}

Player::Player()
    :Player {"None", 0, 0}
{
    
}
Player::Player(std::string name_val)
    :Player{name_val, 0, 0}
{
    
}

Player::Player (std::string name_val, int health_val, int xp_val)
    :name{name_val}, health {health_val}, xp{xp_val}
{

}

void display_player_name (const Player &p)
{
    cout << p.get_name() << endl; //the problem is here, because p is const
}
