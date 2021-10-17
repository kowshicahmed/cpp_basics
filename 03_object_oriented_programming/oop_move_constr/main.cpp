#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Move
{
private: //by default a class is private
    //attributes
    int *data;
public:
    //methods
    void set_data (int d) {*data = d;}
    int get_data () {return *data;}
    
    //overloaded constructors
    Move (int d);
    //copy constructor
    Move (const Move &source); //difference between shallow and deep is in the copy constructor
    //move constructor
    Move (Move &&source) noexcept;
    //destructor
    ~Move ();
};

//function definitions
void display_Move (Move p);


int main(int argc, char **argv)
{
	vector <Move> vec;
    vec.push_back(Move{10});
    vec.push_back(Move{20});
    //vec.push_back(Move{30});
    //vec.push_back(Move{40});
    //vec.push_back(Move{50});
    //vec.push_back(Move{60});
	return 0;
}

Move::Move (int d)
{
    data = new int;
    *data = d;
    cout << "Constructor for: " << d << endl;
}

Move::Move (const Move &source)
    :Move {*source.data}
{
    //data = new int;
    //*data = *source.data;
    cout << "Copy constructor called for: " << *data << endl;
}

Move::Move (Move &&source) noexcept
    :data {source.data}
{
    source.data = nullptr;
    cout << "Move constructor- Moving resource: " << *data << endl;
}

Move::~Move ()
{
    if (data != nullptr)
    {
        cout << "Destructor freeing data for: " << *data << endl;
    }
    else
    {
        cout << "Destructor freeing data for nullptr" << endl;
    }
    delete data;
}

void display_Move (Move p)
{
    cout << p.get_data() << endl;
}