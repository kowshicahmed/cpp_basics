#include <iostream>
#include <vector>

/* * Use of Vectors
 *   Includes vector at, size, push_back funcs and 2d vectors
 *  */

using namespace std;

int main()
{
    vector<int> vector1;
    vector<int> vector2{};

    vector1.push_back(10);
    vector1.push_back(20);

    cout << "Value 1: " << vector1.at(0) << endl;
    cout << "Value 2: " << vector1.at(1) << endl;
    cout << "The size of vector 1 is: " << vector1.size() << endl;

    vector2.push_back(100);
    vector2.push_back(200);

    cout << "Value 1: " << vector2.at(0) << endl;
    cout << "Value 2: " << vector2.at(1) << endl;
    cout << "The size of vector 2 is: " << vector2.size() << endl;

    vector<vector<int>> vector_2d;

    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);

    cout << vector_2d.at(0).at(0) << endl;
    return 0;
}
