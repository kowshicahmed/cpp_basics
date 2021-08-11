#include <iostream>

using namespace std;

class Base
{
public:
    virtual void say_hello () const
    {
        std::cout << "Hello - I am a base class object" << std::endl;
    }
    
    virtual ~Base()
    {
        std::cout << "Base destructor" << std::endl;
    }
};

class Derived final: public Base
{
public:
    //if we do not add the const keyword here it means we are redefining so the function will not be dynamically bound
    //using the override keyword will help us to see if the function signatures are the same (c++11)
    //the final keyword stop further overriding of a class or function
    virtual void say_hello () const override final
    {
        std::cout << "Hello - I am a derived class object" << std::endl;
    }
    
    virtual ~Derived ()
    {
        std::cout << "Derived destructor" << std::endl;
    }
};

int main(int argc, char **argv)
{
	Base *p1 = new Base ();             // Base::say_hello ()
    p1->say_hello();
    
    Derived *p2 = new Derived();    // Derived::say_hello ()
    p2->say_hello();
    
    Base *p3= new Derived();        // Base::say_hello () if there is a mismatch with function signature
    p3->say_hello();
    
    delete p1;
    delete p2;
    delete p3;
    
	return 0;
}
