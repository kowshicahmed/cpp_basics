#include <iostream>

class CanGoWrong
{
public:
    CanGoWrong()
    {
        char *pMemory = new char [9]; // if a large number is allocated the will be bad_alloc excp
        delete[] pMemory;
    }
};

int main()
{
    try 
    {
        CanGoWrong wrong;
    }
    catch(std::bad_alloc &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "Still running" << std::endl;
}