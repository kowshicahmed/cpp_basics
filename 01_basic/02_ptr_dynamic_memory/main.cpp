#include <iostream>
#include <vector>

using namespace std;

/* * Dynamic memory allocation using raw pointer with new keyword
 *  */

int main(int argc, char **argv)
{
    //> dynamic memory allocation using new keyword
    int *int_ptr{nullptr};
    int_ptr = new int;        //> allocate an iteger on the heap
    cout << int_ptr << endl;  //> value of the int_ptr (address)
    cout << *int_ptr << endl; //> dereferencing (will show garbage value)
    *int_ptr = 100;
    cout << *int_ptr << endl; //> 100
    delete int_ptr;           //> frees allocated storage
    cout << endl;

    //> using new[] to allocate storage for an array
    size_t size{0};
    double *temp_ptr{nullptr};
    cout << "How many temps?";
    cin >> size;
    temp_ptr = new double[size];
    cout << temp_ptr << endl;
    delete[] temp_ptr;
    cout << endl;

    return 0;
}
