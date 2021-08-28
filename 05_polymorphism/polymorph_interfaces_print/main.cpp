#include <iostream>

using namespace std;

class Printable
{
    friend ostream &operator<< (ostream &, const Printable &obj);
public:
    virtual void print (ostream &os) const = 0;
    virtual ~Printable () { }
};

ostream &operator<< (ostream &os, const Printable &obj)
{
    obj.print(os);
    return os;
}

class Any_class : public Printable
{
public:
virtual void print (ostream &os) const override
{
    os << "Hi from Any_Class";
}
};

void function1 (Any_class &obj)
{
    cout << obj << endl;
}

int main(int argc, char **argv)
{
	Any_class *ptr = new Any_class ();
    cout << *ptr << endl;
    
    function1(*ptr);
	return 0;
}
