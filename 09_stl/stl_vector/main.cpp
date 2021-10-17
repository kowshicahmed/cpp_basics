#include <iostream>
#include <vector>
#include <algorithm>

class Person
{
    friend std::ostream &operator<<(std::ostream &os, const Person &p);
    std::string name;
    int age;
public:
    Person() = default;
    Person(std::string name, int age)
        : name{name}, age{age} {}
    
    //> we have to always over load the == and < operators to use the stl methods with our class
    bool operator<(const Person &rhs) const
    {
        return this->age < rhs.age;
    }
    bool operator==(const Person &rhs) const            //> this function is not being used for this particular example
    {
        return (this->name == rhs.name && this->age == rhs.age);
    }
};

std::ostream &operator<<(std::ostream &os, const Person &p)
{
    os << p.name << ":" << p.age;
    return os;
}

//> Use for_each and a lambda expression to display vector elements
void display2(const std::vector<int> &vec)
{
    std::cout << "[ ";
    std::for_each(vec.begin(), vec.end(),
            [](int x) {std::cout << x << " ";});
    
    std::cout << "]" << std::endl;
}

//> Template function to display any vector
template <typename T>
void display(const std::vector<T> &vec)
{
    std::cout << "[ ";
    for (const auto &elem: vec)
        std::cout << elem << " ";
    
    std::cout << "]" << std::endl;
}

//> Initializing vectors and displays them
void test1()
{
    std::cout << "\nTest 1 ==============================" << std::endl;
    
    std::vector<int> vec{1,2,3,4,5};
    display(vec);               //> Using the template function
    
    vec = {2,4,5,6};
    display2(vec);
    
    std::vector<int> vec1(10,100);      //> ten 100s in the vector
    display(vec1);                              //> Using the template function
}

//> using the size, max_size, capacity, push_back, shrink_to_fit and reserve methods
void test2()
{
    std::cout << "\nTest 2 ==============================" << std::endl;
    
    std::vector<int> vec {1,2,3,4,5};
    display(vec);
    
    std::cout << "\nvec size: " << vec.size() << std::endl;
    std::cout << "vec max size: " << vec.max_size() << std::endl;
    std::cout << "vec capacity: " << vec.capacity () << std::endl;      //> if the capacity exceeds, the compiler will create a bigger vector
    
    vec.push_back(6);
    display(vec);
    
    std::cout << "\nvec size: " << vec.size() << std::endl;                 //> 6
    std::cout << "vec max size: " << vec.max_size() << std::endl;
    std::cout << "vec capacity: " << vec.capacity () << std::endl;      //> 10
    
    vec.shrink_to_fit();        //> C++ 11
    display(vec);
    
    std::cout << "\nvec size: " << vec.size() << std::endl;                 //> 6
    std::cout << "vec max size: " << vec.max_size() << std::endl;
    std::cout << "vec capacity: " << vec.capacity () << std::endl;      //> 6
    
    vec.reserve(100);           // Reserve 100 capacity
    display(vec);
    
    std::cout << "\nvec size: " << vec.size() << std::endl;
    std::cout << "vec max size: " << vec.max_size() << std::endl;
    std::cout << "vec capacity: " << vec.capacity () << std::endl;
}

//> Accessing elements
void test3()
{
    std::cout << "\nTest 3 ==============================" << std::endl;
    
    std::vector<int> vec{1,2,3,4,5};
    display(vec);
    
    vec[0] = 100;           //> no bounds checking
    vec.at(1) = 200;
    
    display(vec);
}

//> Using the class
void test4()
{
    std::cout << "\nTest 4 ==============================" << std::endl;
    std::vector<Person> stooges;
    
    Person p1 {"Larry", 18};
    display(stooges);
    
    stooges.push_back(p1);
    display(stooges);
    
    stooges.push_back(Person{"Moe", 25});
    display(stooges);
    
    stooges.emplace_back("Curly", 30);      //> Use emplace_back, this will call the constructor
    display(stooges);
}

//> using the class and front, back, pop_back methods
void test5()
{
    std::cout << "\nTest 5 ==============================" << std::endl;
    
    std::vector<Person> stooges
    {
        {"Larry", 18},
        {"Moe", 25},
        {"Curly", 30}
    };
    
    display(stooges);
    std::cout << "\nFront: " << stooges.front() << std::endl;
    std::cout << "Back: " << stooges.back() << std::endl;
    
    stooges.pop_back();
    display(stooges);
}

//> Erasing examples
void test6()
{
    std::cout << "\nTest 6 ==============================" << std::endl;
    std::vector<int> vec {1,2,3,4,5};
    display(vec);
    
    vec.clear();            //> Remove all elements
    display(vec);
    
    vec = {1,2,3,4,5,6,7,8,9,10};
    display(vec);
    vec.erase(vec.begin(), vec.begin() + 2);
    display(vec);
    
    vec = {1,2,3,4,5,6,7,8,9,10};
    
    //> Erase all even numbers
    auto it = vec.begin();
    while (it != vec.end())
    {
        if (*it % 2 == 0)
            vec.erase(it);
        else
            it++;           //> only increame if not erased
    }
    
    display(vec);
}

//> Swap functions
void test7()
{
    std::cout << "\nTest 7 ==============================" << std::endl;
    
    std::vector<int> vec1 {1,2,3,4,5};
    std::vector<int> vec2{10,20,30,40,50};
    
    display(vec1);
    display(vec2);
    std::cout << std::endl;
    
    vec2.swap(vec1);
    display(vec1);
    display(vec2);
}

//> sorting
void test8()
{
    std::cout << "\nTest 8 ==============================" << std::endl;
    
    std::vector<int> vec1 {1,21,3,40,12};
    
    display(vec1);
    std::sort(vec1.begin(), vec1.end());
    display(vec1);
}

//> std::back_inserter constructs a back-insert iterator that inserts new elements
//> at the end of the container it applied to. it is a special output iterator
//> it is awesome and very efficient
//> there is also a fron_inserte we can use with deques and lists
//> copy one list to another using an iterator and back_inserter
void test9 ()
{
    std::cout << "\nTest 9 ==============================" << std::endl;
    
    std::vector<int> vec1 {1,2,3,4,5};
    std::vector<int> vec2 {10,20};
    
    display(vec1);
    display(vec2);
    std::cout << std::endl;
    
    std::copy(vec1.begin(), vec1.end(), std::back_inserter(vec2));      //> insert vec1 in the back of vec2
    display(vec1);
    display(vec2);
    std::cout << std::endl;
    
    //> Copy_if the element is even
    
    vec1 = {1,2,3,4,5,6,7,8,9,10};
    vec2 = {10, 20};
    
    display(vec1);
    display(vec2);
    std::cout << std::endl;
    
    std::copy_if(vec1.begin(), vec1.end(), std::back_inserter(vec2),
            [](int x) {return x%2 == 0;});          //> copy even only
    
    display(vec1);
    display(vec2);
}

//> Transform over 2 ranges
void test10()
{
    std::cout << "\nTest 10 ==============================" << std::endl;
    
    std::vector<int> vec1 {1,2,3,4,5};
    std::vector<int> vec2 {10,20,30, 40, 50};
    std::vector<int> vec3;
    
    // 1*10, 2*20, 3*30, 4*40, 5*50 and store the results in vec3
    std::transform(vec1.begin(), vec1.end(), vec2.begin(),
            std::back_inserter(vec3),
            [](int x, int y) {return x * y;});
    
    display(vec3);
}

//> insert vec2 into vec1 before the 5
void test11()
{
    std::cout << "\nTest 10 ==============================" << std::endl;
    std::vector<int> vec1 {1,2,3,4,5,6,7,8,9,10};
    std::vector<int> vec2 {100,200,300,400};
    
    display(vec1);
    display(vec2);
    std::cout << std::endl;
    
    auto it = std::find(vec1.begin(), vec1.end(), 5);
    if(it != vec1.end())
    {
        std::cout << "inserting...." << std::endl;
        vec1.insert(it, vec2.begin(), vec2.end());
    }
    else
    {
        std::cout << "Sorry, 5 not found" << std::endl;
    }
    display(vec1);
}

int main(int argc, char **argv)
{
	//test1();
    //test2();
    //test3();
    //test4();
    //test5();
    //test6();
    //test7();
    //test8();
    //test9();
    //test10();
    test11();
    
    
	return 0;
}
