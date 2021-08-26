#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Deep
{
private: //by default a class is private
    //attributes
    int *data;
public:
    //methods
    void set_data (int d) {*data = d;}
    int get_data () {return *data;}
    
    //overloaded constructors
    Deep (int d);
    //copy constructor
    Deep (const Deep &source); //difference between shallow and deep is in the copy constructor
    //destructor
    ~Deep ();
};

//function definitions
void display_Deep (Deep p);


int main(int argc, char **argv)
{
	Deep obj1 {100};
    display_Deep (obj1);
    Deep obj2 {obj1};
    obj2.set_data(1000);
	return 0;
}

Deep::Deep (int d)
{
    data = new int;
    *data = d;
}

Deep::Deep (const Deep &source)
    //:Deep {*source.data} //delegating constructor
{
    data = new int; //allocate storage
    *data = *source.data;
    cout << "Copy constructor deep" << endl;
}

Deep::~Deep ()
{
    delete data; //free storage
    cout << "Destructor freeing data" << endl;
}

void display_Deep (Deep p)
{
    cout << p.get_data() << endl;
}