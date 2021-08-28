#include <iostream>

using namespace std;

class Base 
{
private:
    int value;
public:
    Base() : value{0} {cout << "Base no-args constructor" << endl;}
    Base (int x) : value {x} {cout << "Base (int) overloaded constructor" << endl;}
    ~Base () {cout << "Base destructor" << endl;}
};

class Derived:public Base
{
    //using Base::Base; //this class will inherit the specialized base constructors
private:
    int doubled_value;
public:
    Derived () : Base {}, doubled_value {0} {cout << "Derived no-args constructor" << endl;}
    Derived (int x) : Base{x}, doubled_value{x*2} {cout << "Derived (int) overloaded constructor" << endl;} //Base (x) will call the constructor that we want
    //~Derived () {cout << "Derived destructor" << endl;}
};

int main(int argc, char **argv)
{
	//Base b;
    //Base b{100};
    
    //Derived d;
    Derived {1000};
	return 0;
}
