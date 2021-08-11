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
    std::string get_name() {return name;}
    int get_health() {return health;}
    int get_xp() {return xp;}
    
    //overloaded constructors
    Player (std::string name_val = "None", int health_val = 0, int xp_val = 0);
    //copy constructor
    Player (const Player &source);
    //destructor
    ~Player() {cout << "Destructor called for " +name << endl;}
};

//function definitions
void display_player (Player p);


int main(int argc, char **argv)
{
	Player empty_obj;
    display_player(empty_obj);
    
    Player frank {"Frank"};
    Player hero {"Hero", 100};
    Player villain {"Villain", 100, 55};
	return 0;
}

Player::Player (std::string name_val, int health_val, int xp_val)
    :name{name_val}, health{health_val}, xp{xp_val}
{
    cout << "Three_args constr for " + name << endl;     
}

//copy constructor
Player::Player (const Player &source)
    //:name{source.name}, health{source.health}, xp{source.xp} //without deligation
      :Player {source.name, source.health, source.xp} // delegating constructor, this will call the main constractor
{
   cout << "Cpy constr-made cpy of: " << source.name << endl;     
}

void display_player (Player p)
{
    cout << "Name: " << p.get_name() << endl;
    cout << "Health: " << p.get_health() << endl;
    cout << "xp: " << p.get_xp() << endl;
}