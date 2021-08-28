#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

//> Template function to display any deque
template <typename T>
void display (const std::deque <T> &d)
{
    std::cout << "[";
    for (const auto &elem: d)
        std::cout << elem << " ";
    std::cout << "]" << std::endl;
}

//> Initializing and displaying
void test1()
{
    std::cout << "\nTest1 ================================" << std::endl;
    
    std::deque<int> d {1,2,3,4,5};
    display(d);
    
    d = {2,4,5,6};
    display(d);
    
    std::deque<int> d1 (10, 100);       // ten 100s in the deque
    display(d1);
    
    d[0] = 100;                     
    d.at(1) = 200;                      // accessing elements in the middle of a deque is not as efficient
    display(d);
}

//> Push and pops
void test2()
{
    std::cout << "\nTest2 ================================" << std::endl;
    
    std::deque<int> d{0,0,0};
    display(d);
    
    d.push_back(10);
    d.push_back(20);
    display(d);
    
    d.push_front(100);
    d.push_front(200);
    display(d);
    
    std::cout << "Front: " << d.front() << std::endl;
    std::cout << "Back: " << d.back() << std::endl;
    std::cout << "Size: " << d.size() << std::endl;
    
    d.pop_back();
    d.pop_front();
    display(d);
}

//> insert all even numbers into the back of a deque and
//> all odd numbers into the front
void test3()
{
    std::cout << "\nTest3 ================================" << std::endl;
    
    std::vector<int> vec {1,2,3,4,5,6,7,8,9,10};
    std::deque<int> d;
    
    for (const auto &elem: vec)
    {
        if (elem % 2 == 0)
            d.push_back(elem);
        else
            d.push_front(elem);
    }
    display(d);
}

//> Push front vs back ordering
void test4()
{
    std::cout << "\nTest4 ================================" << std::endl;
    
    std::vector<int> vec {1,2,3,4,5,6,7,8,9,10};
    std::deque<int> d;
    
    for (const auto &elem: vec)
    {
        d.push_front(elem);
    }
    display(d);
    
    d.clear();
    
    for (const auto &elem: vec)
    {
        d.push_back(elem);
    }
    display(d);
}

//> Same as test4 using std::copy
void test5()
{
    std::cout << "\nTest5 ================================" << std::endl;
    
    std::vector<int> vec {1,2,3,4,5,6,7,8,9,10};
    std::deque<int> d;
    
    std::copy(vec.begin(), vec.end(), std::front_inserter(d));
    display(d);
    
    d.clear();
    
    std::copy(vec.begin(), vec.end(), std::back_inserter(d));
    display(d);
}

int main(int argc, char **argv)
{
	//test1();
    //test2();
    //test3();
//    test4();
    test5();
	return 0;
}
