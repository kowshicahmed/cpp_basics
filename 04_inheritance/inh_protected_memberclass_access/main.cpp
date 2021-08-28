#include <iostream>

using namespace std;

class Base
{
    //note friends of base have access to all
public:
    int a{0};
    void display() {std::cout << a << "," << b << "," << c << std::endl;} //member method has access to all
protected:
    int b {0};
private:
    int c {0};
};

class Derived: public Base
{
    //note friends of derived have access to only what derived has access to
    
    //a will be public
    //b will be protected
    //c will be inaccessible
    
public:
    void access_base_members () 
    {
        a = 100;    //OK
        b = 200;    //OK
        //c = 300;    //not accessible
    }
};



int main(int argc, char **argv)
{
	cout << "==== Base member access from base objects ======" << std::endl;
    Base base;
    
    base.a = 100; //OK
    //base.b = 200;     //compiler error
    //base.c = 300;     //compiler error
    
    cout << "=== Base member access from derived objects ====" << std::endl;
	Derived d;
    d.a = 100;  //OK
    //d.b = 200;  //compiler error
    //d.c = 300;  //compiler error
    
    return 0;
}
