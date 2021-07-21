#include <iostream>
#include <vector>

/* * Basics of pass by reference
 *   Includes basic use of the & operator with examples like swap and scalling functions
 *  */

using namespace std;

/********** Function Prototypes ***************/
//> Pass by reference examples
void scale_number(int &num);
void swap(int &a, int &b);
void print(vector<int> &v); //> Can use const so that the data can not be changed

/********** Main method ***************/
int main(int argc, char **argv)
{
    int number{1000};
    scale_number(number);
    cout << number << endl;

    int x{10}, y{20};
    cout << "x = " << x << " y = " << y << endl;
    swap(x, y);
    cout << "x = " << x << " y = " << y << endl;

    vector<int> data{1, 2, 3, 4, 5};
    print(data);

    return 0;
}

/********** Helper Functions ***************/
void scale_number(int &num)
{
    if (num > 100)
        num = 100;
}

void swap(int &a, int &b)
{
    int temp{};
    temp = a;
    a = b;
    b = temp;
}

void print(vector<int> &v)
{
    for (auto num : v)
        cout << num << endl;
}