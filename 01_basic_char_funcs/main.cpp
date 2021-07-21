#include <cctype> //< This header allows testing and converting chars
#include <iostream>

/* * Some basic character functions of c++
 *  */

using namespace std;

int main(int argc, char **argv)
{
    int a{};

    a = isalpha('C'); //< True if C is a letter
    cout << a << endl;

    a = isalnum('C'); //< True if C is a letter of digit
    cout << a << endl;

    a = isdigit('C'); //< True if C is a digit
    cout << a << endl;

    a = islower('C'); //< True if C is a lowercase letter
    cout << a << endl;

    a = isprint('C'); //< True if C is a printable character
    cout << a << endl;

    a = ispunct('C'); //< True if C is a punctutation character
    cout << a << endl;

    a = isupper('C'); //< True if C is an uppercase letter
    cout << a << endl;

    a = isspace('C'); //< True if C is whitespace
    cout << a << endl;

    return 0;
}
