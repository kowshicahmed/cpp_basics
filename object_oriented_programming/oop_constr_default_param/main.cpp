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
    Player (std::string name_val = "None", int health_val = 0, int xp_val = 0);
};



int main(int argc, char **argv)
{
	Player empty_obj;
    Player frank {"Frank"};
    Player hero {"Hero", 100};
    Player villain {"Villain", 100, 55};
	return 0;
}



Player::Player (std::string name_val, int health_val, int xp_val)
    :name{name_val}, health{health_val}, xp{xp_val}
{
    cout << "Three_args constr" << endl;     
}
    
