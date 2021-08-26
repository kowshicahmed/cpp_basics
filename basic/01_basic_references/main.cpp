#include <iostream>
#include <vector>

/* * Example of references with range based for loop and variables
 *  */

using namespace std;

int main(int argc, char **argv)
{
    //> Example with vector
    vector<string> stooges{"larry", "moe", "curly"};
    for (auto str : stooges)
        str = "Funny"; //> Changes the copy not stooges
    for (auto str : stooges)
        cout << str << endl;

    for (auto &str : stooges)       //> If we add 'auto const &str' it will be comp error
        str = "Funny";              //> Changes the vector because of the reference
    for (auto const &str : stooges) //> For display auto const &str is ok
        cout << str << endl;

    //> Example with variable
    int num{100};
    int &ref{num};

    cout << num << endl;
    cout << ref << endl;

    num = 200;
    cout << num << endl;
    cout << ref << endl;

    ref = 300;
    cout << num << endl;
    cout << ref << endl;
    return 0;
}
