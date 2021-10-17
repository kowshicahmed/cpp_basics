#include <iostream>
#include "Player.h"

using namespace std;

void display_active_players()
{
    cout << "Active players: " << Player::get_num_players() << endl;
}

int main(int argc, char **argv)
{
	display_active_players();
    Player hero {"Hero"};
    display_active_players();
    
    {
        Player frank {"frank"};
        display_active_players();
    }
    display_active_players();
    
    Player *enemy = new Player ("enemy", 100, 100);
    display_active_players();
    delete enemy;
    display_active_players();
	return 0;
}
