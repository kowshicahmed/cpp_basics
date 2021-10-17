#include <iostream>
#include <string>

//> Class template - Array

//> Note: Since C++11 the STL has std::array which is a template-based array class
//> Use std::array instead of raw arrays whenever possible

//> It is possible to have non "typename" parameters using template i.e we can have variables in template
//> For example: Array <5> arr; here N=5 will be the size of the array 
template <typename T, int N>
class Array
{
    int size {N};       //> How do we get the N??
    //> values can be of any type
    T values [N];     //> The N needs to be known at compile-time
    
    //> We have two template parameters so this function needs to have T
    friend std::ostream &operator<< (std::ostream &os, const Array<T, N> &arr)  // This function needs to know about N
    {
        os << "[ ";
        for (const auto &val: arr.values)
            os << val << " ";
        os << " ]" << std::endl;
        return os;
    }
    
public:
    Array () = default;
    Array (T init_val)      //> Initial value can be of any type
    {
        for (auto &item: values)
            item = init_val;
    }
    
    void fill (T val)           //> Fill can be of any type
    {
        for (auto &item: values)
        {
            item = val;
        }
    }
    int get_size () const
    {
        return size;
    }
    //> Overloading subscript operator for easy use
    T &operator[] (int index)       //> Return a reference to T
    {
        return values[index];
    }
};

int main(int argc, char **argv)
{
	Array <int, 5> nums;        // Need to provide both template parameters
    std::cout << "The size of nums is: " << nums.get_size () << std::endl;
    std::cout << nums << std::endl;
    
    nums.fill (0);
    std::cout << "The size of nums is: " << nums.get_size () << std::endl;
    std::cout << nums << std::endl;
    
    nums.fill (10);
    std::cout << nums << std::endl;
    
    nums [0] = 1000;        //> nums.operator[] (0) is called
    nums [3] = 2000;        //> nums.operator[] (3) is called
    std::cout << nums << std::endl;
    
    Array <int, 100> nums2 {1};
    std::cout << "The size of nums2 is: " << nums2.get_size () << std::endl;
    std::cout << nums2 << std::endl;
    
    Array <std::string, 10> strings {std::string {"Frank"}};
    std::cout << "The size of strings is: " << strings.get_size () << std::endl;
    std::cout << strings << std::endl;
    
    strings[0] = std::string {"Larry"};
    std::cout << strings << std::endl;
    
    strings.fill(std::string{"X"});
    std::cout << strings << std::endl;
    
	return 0;
}
