#include <iostream>
#include <exception>

void goesWrong()
{
    //if we change error1 to false and 2 to true, then the main is fine
    //if both are true then only bad_alloc will be thrown
    bool error1Detected = true;
    bool error2Detected = false;

    if(error1Detected)
    {
        throw std::bad_alloc();
    }

    if(error2Detected)
    {
        throw std::exception();
    }
}

int main()
{
    try
    {
        goesWrong();
    }
    // this will catch the bad_alloc excp if added before bad_alloc catch block
    catch(const std::exception& e)          
    {
        std::cerr << e.what() << '\n';
    }
    catch(const std::bad_alloc& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}