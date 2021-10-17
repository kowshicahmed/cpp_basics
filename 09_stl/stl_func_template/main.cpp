#include <iostream>
#include <string>

//> Template function for determining minimum of two variables of any type
template <typename T>
T min (T a, T b)
{
    return (a < b) ? a : b;
}

//> Template function for printing two variables of any type
template <typename T1, typename T2>
void func (T1 a, T2 b)
{
    std::cout << a << " " << b << std::endl;
}

//> For a struct or class we need to overload the operator present in the template function
struct Person
{
    std::string name;
    int age;
    
    bool operator< (const Person &rhs) const
    {
        return this->age < rhs.age;
    }
};

//> Overloading the stream insertion operator
std::ostream &operator<< (std::ostream &os, const Person &p)
{
    os << p.name;
    return os;
}

//> Swap function template
template <typename T>
void my_swap (T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

/********** Main method ***************/
int main(int argc, char **argv)
{
	//> Using the swap function
    std::cout  << "------------------------------------------- " <<  std::endl;
    int x{100};
    int y{200};
    std::cout << x << ", " << y << std::endl;
    my_swap (x, y);
    std::cout << x << ", " << y << std::endl;
    
    std::string a {"Akash"};
    std::string b {"Batash"};
    std::cout << a << ", " << b << std::endl;
    my_swap (a, b);
    std::cout << a << ", " << b << std::endl;
    
    //> Using the struct with min and func function
    std::cout  << "------------------------------------------- " <<  std::endl;
    Person p1 {"Curly", 15};
    Person p2 {"Moe", 30};
    
    Person p3 = min (p1,p2); //> Need to overload the comparison operator
    
    std::cout << p3.name << " is younger" << std::endl;
    
    func (p1,p2); //> Need to overload the insersion << operator
    
    //> Using the min function with different data types
    std::cout  << "------------------------------------------- " <<  std::endl;
    std::cout << min <int> (2,3) << std::endl;      // 2
    std::cout << min (2,3) << std::endl;                //2
    std::cout << min ('A', 'B') << std::endl;           //A
    std::cout << min (12.5, 9.2) << std::endl;      //9.2
    std::cout << min (5+2*2, 7+40) << std::endl;    //9
    
    //> Using the func function with different data types
    std::cout  << "------------------------------------------- " <<  std::endl;
    func <int, int> (10, 20);
    func (10,20);
    func <char, double> ('A', 12.4);
    func ('A', 12.4);
    func (1000, "Testing");
    func (2000, std::string{"Frank"});
    
	return 0;
}
