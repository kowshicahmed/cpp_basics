#include <iostream>
#include <vector>
#include "Mystring.h"

using namespace std;

int main(int argc, char **argv)
{
	Mystring a {"hello"};       //overloaded constructor
    Mystring b;                 //no-args constructor
    b = a;                      //copy assignment
                                //b.operator=(a)
    b = "this is a test";       //b.operator=("this is a test");
    
    Mystring empty;             //no-args constructor
    Mystring larry {"larry"};   //copy constructor
    Mystring stooge {larry};    //copy constructor
    Mystring stooges;           //no-args constructor
    
    empty = stooge;             //copy assignment operator
    empty.display();            //larry : 5
    
    stooges = "larry, moe and curly"; //copy assignment
    stooges.display();
    
    //using vector
    vector <Mystring> stooges_vec;
    stooges_vec.push_back("larry");
    stooges_vec.push_back("moe");
    stooges_vec.push_back("curly");
    
    cout << "========Loop 1===========" << endl;
    for (const Mystring &s: stooges_vec)
        s.display();                                //display the vector
    
    cout << "=======Loop 2==========" << endl;
    for (Mystring &s:stooges_vec)
        s = "changed";                              //copy assignment
    
    cout << "=======Loop 3==========" << endl;
    for (const Mystring &s:stooges_vec)
        s.display();                                //changed, changed
    return 0;
}
