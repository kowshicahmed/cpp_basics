#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>

//> Display the array -- note the size must be included
//> when passing a std::array to a function
void display (const std::array <int, 5> &arr)
{
    std::cout << "[ ";
    for (const auto &i: arr)
        std::cout << i << " ";
    std::cout << " ]" << std::endl;
}

//> Basic array initialization syntax, sizeof, front and back functions
void test1 ()
{
    std::cout << "\nTest1==============================" << std::endl;
    std::array <int, 5> arr1 {1, 2, 3, 4, 5};       //double {{ }} if c++ 11
    std::array <int, 5> arr2;
    
    display (arr1);
    display (arr2);         //> Elements are not initialized (contain garbage)
    
    arr2 = {10, 20, 30, 40, 50};
    
    display (arr1);
    display (arr2);
    
    std::cout << "Size of arr1 is: " << arr1.size () << std::endl;       //5
    std::cout << "Size of arr2 is: " << arr2.size () << std::endl;      //5
    
    arr1[0] = 1000;         //> Does not do bounds checking
    arr1.at(1) = 2000;     //> Does bound checking 
    display (arr1);
    
    std::cout << "Front of arr2: " << arr2.front() << std::endl;        //10
    std::cout << "Back of arr2: " << arr2.back() << std::endl;         //50
}

//> Fill and swap methods
void test2 ()
{
    std::cout << "\nTest2==============================" << std::endl;
    std::array<int, 5> arr1 {1, 2, 3, 4, 5};        //> Double {{ }} if c++11
    std::array<int, 5> arr2 {10, 20, 30, 40, 50};
    
    display (arr1);
    display (arr2);
    
    arr1.fill (0);
    
    display (arr1);
    display (arr2);
    
    arr1.swap(arr2);
    
    display (arr1);
    display (arr2);
}

//> Getting the raw array pointer
void test3 ()
{
    std::cout << "\nTest3==============================" << std::endl;
    
    std::array<int, 5> arr1 {1,2,3,4,5};                //> Double {{ }} if c++11
    
    int *ptr = arr1.data();                                 //> The address of the first element is returned
    std::cout << ptr << std::endl;
    *ptr = 10000;
    
    display(arr1);
}

//> Sorting array
void test4 ()
{
    std::cout << "\nTest4==============================" << std::endl;
    
    std::array<int, 5>arr1{2,1,4,5,3};               //> Double {{ }} if c++11
    display(arr1);
    
    std::sort(arr1.begin(), arr1.end());            //> Must include algorithm header for this
    display(arr1);
}

//> Find minimum maximum number
void test5 ()
{
    std::cout << "\nTest5==============================" << std::endl;
    
    std::array<int, 5> arr1{2,1,4,5,3};             //> Double {{ }} if c++11
    
    std::array<int, 5>::iterator min_num = std::min_element(arr1.begin(), arr1.end());
    auto max_num = std::max_element(arr1.begin(), arr1.end());
    std::cout << "min: " << *min_num << ", max: " << *max_num << std::endl;
}

//> Find adjacent elements
void test6 ()
{
    std::cout << "\nTest6==============================" << std::endl;
    
    std::array<int, 5> arr1 {2,1,3,3,5};        //> Double {{ }} if c++11
    
    auto adjacent = std::adjacent_find(arr1.begin(), arr1.end());
    if (adjacent != arr1.end())
        std::cout << "Adjacent element found with value: " << *adjacent << std::endl;
    else
        std::cout << "No adjacent elements found" << std::endl;
}

//> use of accumulate function
void test7 ()
{
    std::cout << "\nTest7==============================" << std::endl;
    
    //> accumulate is from numeric header
    std::array <int, 5> arr1 {1,2,3,4,5};           //> Double {{ }} if c++11
    
    int sum = std::accumulate(arr1.begin(), arr1.end(), 0);         //> sum will start at 0
    std::cout << "Sum of the elements in arr1 is: " << sum << std::endl;
}

//> use of count
void test8 ()
{
    std::cout << "\nTest8==============================" << std::endl;
    std::array <int, 10> arr1 {1,2,3,1,2,3,3,3,3,3};
    
    int count = std::count(arr1.begin(), arr1.end(), 3);
    std::cout << "Found 3: " << count << " times" << std::endl;
}

//> use of count_if using lambda expression
void test9 ()
{
    std::cout << "\nTest9==============================" << std::endl;
    
    std::array <int, 10> arr1 {1, 2, 3, 50, 60, 70, 80, 200, 300, 400};
    //> Find how many numbers are between 10 and 200 -> 50, 60, 70, 80
    
    int count = std::count_if (arr1.begin (), arr1.end(), [](int x) {return x > 10 && x < 200;});
    std::cout << "Found " << count << " matches" << std::endl;
    
}

int main(int argc, char **argv)
{
	//test1 ();
    //test2 ();
    //test3 ();
    //test4 ();
    //test5 ();
    //test6 ();
    //test7 ();
    //test8 ();
    test9 ();
	return 0;
}
