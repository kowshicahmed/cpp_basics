#include <iostream>
#include <vector>

/* * Basics of pointer using functions
 *    Returning pointer from functions
 *    Dynamic memory allocation
 *  */

using namespace std;

//pass by reference example
void double_data(int *int_ptr); //doubles the value passed
void swap(int *a, int *b);
void display(const vector<string> *const v);
void display(const int *arr, int sentinel);

//returning a pointer from function example
int *largest(int *a, int *b);

//dynamic memory and return pointer example
int *create_array(size_t size, int init_value = 0); //has a default value for init
void display(const int *const arr, size_t size);

int main(int argc, char **argv)
{
    int value{10};
    cout << "Value is: " << value << endl;
    double_data(&value);
    cout << "Value is: " << value << endl;

    int *int_ptr{nullptr};
    int_ptr = &value;
    double_data(int_ptr);
    cout << "Value is: " << value << endl;

    //example - 2
    int x{100}, y{200};
    cout << "x = " << x << " y = " << y << endl;
    swap(&x, &y);
    cout << "x = " << x << " y = " << y << endl;

    //example -3
    vector<string> stooges{"larry", "moe", "curly"};
    display(&stooges);

    int scores[]{100, 98, 97, 79, 85, -1};
    display(scores, -1);

    //return pointer example
    int num1{100}, num2{200};
    int *comp_ptr = largest(&num1, &num2);
    cout << "The largest number is: " << *comp_ptr << endl;
    cout << endl;

    //dynamic memory and return pointer example
    int *my_array{nullptr};
    size_t size{};
    int init_value{};

    cout << "How many values do you want? : ";
    cin >> size;
    cout << "Enter init value: ";
    cin >> init_value;

    my_array = create_array(size, init_value);
    display(my_array, size);
    delete[] my_array;

    return 0;
}

void double_data(int *int_ptr)
{
    *int_ptr *= 2;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display(const vector<string> *const v)
{
    for (auto c : *v)
    {
        cout << c << " ";
    }
    cout << endl;
}

void display(const int *arr, int sentinel)
{
    while (*arr != sentinel)
    {
        cout << *arr << endl;
        arr++;
    }
}

int *largest(int *a, int *b)
{
    if (*a > *b)
        return a;
    else
        return b;
}

int *create_array(size_t size, int init_value)
{
    int *new_storage{nullptr};
    new_storage = new int[size];
    for (size_t i{0}; i < size; ++i)
    {
        *(new_storage + i) = init_value;
    }

    return new_storage;
}

void display(const int *const arr, size_t size)
{
    for (size_t i{0}; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}