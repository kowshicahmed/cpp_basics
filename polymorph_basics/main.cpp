#include <iostream>
#include <memory>

using namespace std;

class Base
{
public:
    void say_hello () const
    {
        std::cout << "Hello - I am a base class object" << std::endl;
    }
};

class Derived : public Base
{
public:
    void say_hello () const
    {
        std::cout << "Hello - I am a derived class object" << std::endl;
    }
};

void greetings (const Base &obj)
{
    std::cout << "Greetings: " ;
    obj.say_hello();
}

int main(int argc, char **argv)
{
	Base b;
    b.say_hello ();
    
    Derived d;
    d.say_hello ();
    
    greetings(b); //calls base say hello function
    greetings(d); //does not call derived say hello function due to static binding
    
    Base *ptr = new Derived (); //this is valid since derived is a base
    ptr->say_hello (); //we probably wanted to call the derived say hello function
    
    std::unique_ptr<Base> ptr1 = std::make_unique <Derived>();
    ptr1->say_hello (); //smart pointers are also statically bound
	return 0;
}
