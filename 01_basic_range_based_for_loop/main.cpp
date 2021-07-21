#include <iostream>
#include <vector>
#include <iomanip> //> Manipulates/formats io

/* * Basics of range based for loops
 *   Inlcudes examples with array, vector,  strings, references
 *  */

using namespace std;

int main(int argc, char **argv)
{

    //> Example-1 with array
    int scores[]{100, 90, 97};

    for (int score : scores)
    {
        cout << score << endl;
    }

    //> Example 2 with vector
    vector<double> temps{87.2, 77.1, 80.0, 72.5};
    double average_temp{};
    double running_sum{};

    for (auto temp : temps) //> The compiler figuers out the type with auto keyword
    {
        running_sum += temp;
    }

    if (temps.size() != 0)
    {
        average_temp = running_sum / temps.size();
    }

    cout << fixed << setprecision(1); //> Set decimal point
    cout << "Average temp:" << average_temp << endl;

    //> Example 3 with strings
    for (auto c : "this is a test")
    {
        if (c == ' ')
            cout << "\t";
        else
            cout << c;
    }
    cout << endl;

    //> Example with reference
    vector<string> stooges{"larry", "moe", "curly"};
    for (auto str : stooges)
        str = "Funny"; //> Changes the copy not stooges

    for (auto str : stooges)
        cout << str << endl;

    for (auto &str : stooges) //> If we add 'auto const &str' it will be comp error
        str = "Funny";        //> Changes the vector because of the reference

    for (auto const &str : stooges) //> For display auto const &str is ok
        cout << str << endl;

    cout << endl;

    return 0;
}
