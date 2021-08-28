#include <iostream>
#include <vector>
#include <iomanip>
#include "Mystring.h"

using namespace std;

int main(int argc, char **argv)
{
	cout << boolalpha << endl;
    
    Mystring larry {"Larry"};
    Mystring moe {"Moe"};
    
    Mystring stooge = larry;
    larry.display();
    moe.display();
    
    cout << (larry == moe) << endl;         //false
    cout << (larry == stooge) << endl;      //true
    
    larry.display();                        //Larry
    Mystring larry2 = -larry;
    larry2.display();                       //larry
    
    //Mystring stooges = larry + "Moe";       //ok with member function
    Mystring stooges = "Larry" + moe;         //now ok with non member function
    
    Mystring two_stooges = moe + " " +"Larry";
    two_stooges.display();
    
    Mystring three_stooges = moe + " " + larry + " " + "Curly";
    three_stooges.display();
    return 0;
}
