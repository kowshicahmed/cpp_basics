#include <iostream>
#include "Mystring.h"

using namespace std;

int main(int argc, char **argv)
{
	Mystring empty;             //no-args constructor
    Mystring larry {"Larry"};   //overloaded constructor
    Mystring stooge {larry};    //copy constructor
    
    empty.display();
    larry.display();
    stooge.display();
    
	return 0;
}
