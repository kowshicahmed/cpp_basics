#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player
{
    public: //by default a class is private
    //attributes
    string name;
    int health;
    int xp;
    //methods
    void talk (string text_to_say) {cout << name << " says " << text_to_say<<endl;}
    bool is_dead ();
};

class Account
{
    public:
    //attributes
    string name {"Account"}; //initializing is also possible
    double balance {0.0};
    //methods
    bool deposit (double bal) {balance+=bal;cout<<"In deposit"<<endl;return 0;}
    bool withdraw (double bal){balance-=bal;cout<<"In withdraw"<<endl;return 0;}
};

int main(int argc, char **argv)
{
	//player example
    Player frank; //object 1
    Player hero; //object 2
    Player players [] {frank, hero}; //players is an array that can contain objects of player class
    vector <Player> player_vec {frank}; //a vector of player objects
    player_vec.push_back(hero);
    
    //accessing class members
    frank.name = "Frank";
    frank.health = 100;
    frank.xp = 12;
    frank.talk("Hi there");
    
    //using pointer
    Player *enemy {nullptr};
    enemy = new Player; //allocate memory in the heap
    (*enemy).name = "Enemy";
    (*enemy).health = 100;
    enemy->xp = 15; //instead of dot operator we can use ->
    enemy->talk("I will destroy you!");
    delete enemy;
    
    //account example
    Account frank_account;
    Account jim_account;
    frank_account.name = "Frank's account";
    frank_account.balance = 5000.0;
    frank_account.deposit(1000);
    frank_account.withdraw(500);
	return 0;
}
