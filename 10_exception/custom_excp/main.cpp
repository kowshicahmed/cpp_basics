#include <iostream>
#include <exception>

class MyException: public std::exception 
{
public:
    //throw() means this function cannot throw an exception
    virtual const char* what() const throw() 
    {
        return "Something bad happended";
    }
};

class Test
{
public:
    void goesWrong()
    {
        throw MyException();
    }
};

int main()
{
    Test test;

    try
    {
        test.goesWrong();
    }
    catch(MyException& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}