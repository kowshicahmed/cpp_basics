#include <iostream>
#include <vector>

/* * Pointer Basics
 *    Use of address operator, size of pointer, dereferencing
 *    Examples with vector and string
 *  */

using namespace std;

int main(int argc, char **argv)
{
    //> Using the address operator
    int num{10};
    cout << "Value of num is: " << num << endl;
    cout << "Size of num is: " << sizeof num << endl;
    cout << "Address of num is: " << &num << endl
         << endl;
    cout << "---------------------" << endl;

    //> pointer basic example
    int *p;
    cout << "Value of p is: " << p << endl; // garbage value
    cout << "Address of p is: " << &p << endl;
    cout << "Size of p is: " << sizeof p << endl;
    p = nullptr; //set p to point nowhere
    cout << "Value of p is: " << p << endl
         << endl; // no value
    cout << "---------------------" << endl;
    //> Pointer size example
    int *p1{};
    double *p2{};
    unsigned long long *p3{};
    vector<string> *p4{};
    string *p5{};

    cout << "\nsize of p1 is: " << sizeof p1 << endl;
    cout << "size of p2 is: " << sizeof p2 << endl;
    cout << "size of p3 is: " << sizeof p3 << endl;
    cout << "size of p4 is: " << sizeof p4 << endl;
    cout << "size of p5 is: " << sizeof p5 << endl
         << endl;
    cout << "---------------------" << endl;

    //> Storing address example
    int score{10};
    double high_temp{100.7};

    int *score_ptr{nullptr};

    score_ptr = &score;
    cout << "Value of score is: " << score << endl;
    cout << "Adress of score is: " << &score << endl;
    cout << "Value of score_ptr is: " << score_ptr << endl;                   // should be same as &score
    cout << "Value of what score_ptr is pointing to: " << *score_ptr << endl; //dereferencing a pointer
    *score_ptr = 200;                                                         //using the pointer to change the value of score
    cout << "Value of score is: " << score << endl;
    cout << "Value of what score_ptr is pointing to: " << *score_ptr << endl;

    //> More examples of dereferencing
    double low_temp{37.4};
    double *temp_ptr{&low_temp};
    cout << "Low temp: " << *temp_ptr << endl;
    temp_ptr = &high_temp;
    cout << "high temp: " << *temp_ptr << endl;

    //> Example with strings
    string name{"Frank"};
    string *string_ptr{&name};
    cout << "String value: " << *string_ptr << endl;
    name = "James";
    cout << "String value: " << *string_ptr << endl;

    //> Example with vector
    vector<string> stooges{"larry", "moe", "curly"};
    vector<string> *vector_ptr{nullptr};
    vector_ptr = &stooges;
    cout << "First stooge: " << (*vector_ptr).at(0) << endl;

    cout << "stooges: ";
    for (auto stooge : *vector_ptr)
        cout << stooge << " ";
    cout << endl;
    cout << endl;
    return 0;
}
