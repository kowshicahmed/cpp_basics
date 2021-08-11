#include <iostream>
#include <vector>

/* * Using pointer with arrays
 *  */

using namespace std;

int main(int argc, char **argv)
{
    //relationship between arrays and pointers
    cout << "relationship between arrays and pointers" << endl;
    int scores[]{100, 200, 300, 400};
    cout << scores << endl;  //address of the first element of the array
    cout << *scores << endl; //100

    int *score_ptr{scores};
    cout << score_ptr << endl;        //address of the first element of the array
    cout << (score_ptr + 1) << endl;  //the address gets incremented by 4
    cout << *score_ptr << endl;       //100
    cout << *(score_ptr + 1) << endl; //200
    cout << score_ptr[1] << endl;     //200
    cout << endl;

    //pointer arithmetic
    cout << "pointer arithmetic" << endl;
    int temps[]{100, 95, 89, 68, -1};
    int *temp_ptr{temps};

    while (*temp_ptr != -1)
    {
        cout << *temp_ptr << endl;
        temp_ptr++;
    }
    cout << endl;

    //another example, does the same thing as before
    temp_ptr = temps;
    while (*temp_ptr != -1)
    {
        cout << *temp_ptr++ << endl; //derefence first, then increment
    }
    cout << endl;
    return 0;
}
