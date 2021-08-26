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
    
    std::string get_name ()
    {
        return name;
    }
    
    //overloaded constructors
    
    Player ()
    {
        name = "None";
        health = 100;
        xp = 3;
    }
    
    Player (std::string name_val, int health_val, int xp_val)
    {
        name = name_val;
        health = health_val;
        xp = xp_val;
    }
};



int main(int argc, char **argv)
{
	Player frank; //if no constructors are declared or default constructor is declared this will work
    frank.set_name("Frank");
    cout << frank.get_name() << endl;
	return 0;
}
