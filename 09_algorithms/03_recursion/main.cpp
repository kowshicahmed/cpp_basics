#include <iostream>

int factorial(int n) 
{
    if (n == 1) 
        return 1;
    else
        return n * factorial(n-1);
}

int factorial_visualisation(int n) 
{
    std::cout << "Computing " << n << std::endl;
    if (n == 1) 
    {
        std::cout << "Result for " << n << " is " << n << std::endl;
        return 1;
    }
    else
    {
        int result = factorial_visualisation(n-1);
        std::cout << "Result for " << n << " is " << n * result << std::endl;
        return n * result;
    }

}

int main()
{
    //std::cout << "The Factoria of 4 is: " << factorial(4) << std::endl;
    factorial_visualisation(4);
    return 0;
}