#include <iostream>

/* * How to pass an array to a function
 *  */

/********** Function Prototypes ***************/
void print_array(const int arr[], size_t size);    //< Prints the values of an array that was passed
void set_array(int arr[], size_t size, int value); //< Sets the values of an array given the size and members

/********** Main method ***************/
int main(int argc, char **argv)
{
    int numbers[]{1, 2, 3, 4, 5};

    print_array(numbers, 5);
    set_array(numbers, 5, 100);
    print_array(numbers, 5);

    return 0;
}

/********** Helper Functions ***************/
void print_array(const int arr[], size_t size)
{
    for (size_t i{0}; i < size; ++i)
    {
        std::cout << arr[i] << " ";             //> Add a space after each value
    }
    std::cout << std::endl;
}

void set_array(int arr[], size_t size, int value)
{
    for (size_t i{0}; i < size; ++i)
    {
        arr[i] = value;
    }
}