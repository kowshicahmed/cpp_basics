#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player
{
private: //by default a class is private
    //attributes
    string name {"Player"};
    int health;
    int xp;
public:
    //methods
    void talk (string text_to_say) {cout << name << " says " << text_to_say<<endl;}
    bool is_dead ();
};



int main(int argc, char **argv)
{
	Player frank;
    //frank.name = "frank; //error
    //cout << frank.health << endl; //error
    frank.talk("Hello there");
	return 0;
}
