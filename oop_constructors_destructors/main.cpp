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
    void set_name (std::string name_val)
    {
        name = name_val;
    }
    
    //overloaded constructors
    Player() //default constructor
    {
        cout << "no args constructor called" << endl;
    }
    
    Player(std::string name)
    {
        cout << "String arg constructor called" << endl;
    }
    
    Player(std::string name, int health, int xp)
    {
        cout << "Three args constructor called" << endl;
    }
    
    ~Player ()
    {
        cout << "Destructor called for " << name << endl;
    }
};



int main(int argc, char **argv)
{
	{
        Player slayer;
        slayer.set_name("slayer");
    }
    
    {
        Player frank;
        frank.set_name("Frank");
        Player hero("hero");
        hero.set_name("Hero");
        Player villain ("Villain", 100, 12);
        villain.set_name("Villain");
    }
    
    Player *enemy = new Player;
    enemy->set_name("Enemy");
    
    Player *level_boss = new Player ("Level boss", 1000, 300);
    level_boss->set_name("Level boss");
    
    delete enemy;
    delete level_boss;
    
	return 0;
}
