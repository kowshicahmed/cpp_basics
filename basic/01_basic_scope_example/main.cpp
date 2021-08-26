#include <iostream>

/* * Example of scope using parentheses
 *  */

using namespace std;

int main(int argc, char **argv)
{
    int num{100};  //> Local to main
    int num1{500}; //> Local to main
    cout << "Local num is: " << num << " in main" << endl;
    {
        //> Creating new level of scope
        int num{200}; //> Local to this inner block
        cout << "Local num is: " << num << " in inner block in main" << endl;
        cout << "Inner block main can see out num1 is: " << num1 << endl;
    }

    cout << "Local num is: " << num << " in main" << endl;

    return 0;
}
