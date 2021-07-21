#include <iostream>
#include <vector>

/* * Basics of nested loops with an example of multiplication table and histogram
 *  */

using namespace std;

int main()
{
    //> Code for printing out a multiplication table from 1 to 10
    for (int num1{1}; num1 <= 10; ++num1)
    {
        for (int num2{1}; num2 <= 10; ++num2)
        {
            cout << num1 << "*" << num2 << "=" << num1 * num2 << endl;
        }
        cout << "--------------" << endl;
    }

    //> Code for histogram
    vector<int> data{};
    int num_items{0};

    cout << "How many items: ";
    cin >> num_items;

    for (int i{1}; i <= num_items; ++i)
    {
        int data_item{};
        cout << "Enter data " << i << ":";
        cin >> data_item;
        data.push_back(data_item);
    }

    cout << "\nDisplaying Histogram" << endl;
    for (auto val : data)
    {
        for (int i{1}; i <= val; ++i)
        {
            if (i % 5 == 0)
                cout << "*";
            else
                cout << "-";
        }

        cout << endl;
    }

    cout << endl;

    return 0;
}
