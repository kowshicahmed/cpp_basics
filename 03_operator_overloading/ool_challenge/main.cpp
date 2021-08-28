#include <iostream>
#include <iomanip>
#include "Mystring.h"

using namespace std;

int main(int argc, char **argv)
{
	cout << boolalpha << endl;
    
    Mystring a {"Frank"};
    Mystring b {"Geroge"};
    
    cout << (a < b) << endl;
    cout << (a > b) << endl;
    b = b*3;
    cout << b << endl;
    cout << a << endl;
    a+=b;
    cout << a << endl;
	return 0;
}
