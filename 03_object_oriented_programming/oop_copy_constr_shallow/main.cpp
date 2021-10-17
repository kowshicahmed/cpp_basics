#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Shallow
{
private: //by default a class is private
    //attributes
    int *data;
public:
    //methods
    void set_data (int d) {*data = d;}
    int get_data () {return *data;}
    
    //overloaded constructors
    Shallow (int d);
    //copy constructor
    Shallow (const Shallow &source);
    //destructor
    ~Shallow ();
};

//function definitions
void display_shallow (Shallow p);


int main(int argc, char **argv)
{
	Shallow obj1 {100};
    display_shallow (obj1);
    Shallow obj2 {obj1};
    obj2.set_data(1000);
	return 0;
}

Shallow::Shallow (int d)
{
    data = new int;
    *data = d;
}

Shallow::Shallow (const Shallow &source)
    :data (source.data)
{
    cout << "Copy constructor" << endl;
}

Shallow::~Shallow ()
{
    delete data; //free storage
    cout << "Destructor freeing data" << endl;
}

void display_shallow (Shallow p)
{
    cout << p.get_data() << endl;
}