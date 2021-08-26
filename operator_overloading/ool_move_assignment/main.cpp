#include <iostream>
#include <vector>
#include "Mystring.h"

using namespace std;

int main(int argc, char **argv)
{
	Mystring a {"hello"};       //overloaded constructor
    a = Mystring {"hola"};      //overloaded constructor then move assignment
    a = "bonjour";              //overloaded constructor then move assignment
    
    Mystring b;                 //no-args constructor
    b = a;                      //copy assignment
    
    Mystring empty;             //no-args constructor
    Mystring larry {"larry"};   //overloaded constructor
    Mystring stooge {larry};    //copy constructor
    Mystring stooges;           //no-args constructor
    empty = stooge;             //copy assignment, stooge is an l-value
    
    empty = "funny";            //move assignment, "funny" is r-value
    
    return 0;
}
