#include <iostream>

/* * Two use cases of recursive functions
 *   Includes examples of factorial and fibonacci function
 *  */

using namespace std;

/********** Function Prototypes ***************/
unsigned long long factorial(unsigned long long n);
unsigned long long fibonacci(unsigned long long n);

/********** Main method ***************/
int main(int argc, char **argv)
{
    cout << factorial(8) << endl;
    cout << fibonacci(3) << endl;
    cout << fibonacci(5) << endl;
    return 0;
}

/********** Helper Functions ***************/
unsigned long long factorial(unsigned long long n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

unsigned long long fibonacci(unsigned long long n)
{
    if (n <= 1)
        return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}