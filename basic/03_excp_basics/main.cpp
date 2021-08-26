#include <iostream>

int main()
{
	int miles {};
    int gallons {};
    double miles_per_gallon {};
    
    
    std::cout << "Enter the miles: ";
    std::cin >> miles;
    std::cout << "Enter gallons: ";
    std::cin >> gallons;
    /*
    std::cout << "========== Without Exception Handeling =============" << std::endl;
    if (gallons != 0)
    {
        miles_per_gallon = miles / gallons; //divide zero is program crash
        //miles_per_gallon = static_cast<double> (miles) / gallons; //divide by zero is infinity 
        std::cout << "Result: " << miles_per_gallon << std::endl;
    }
    else
    {
        std::cerr << "Sorry, can't divide by zero" << std::endl;
    }
    
    std::cout << "Bye " << std::endl;
    */
    
    std::cout << "========== With Exception Handeling =============" << std::endl;
    try 
    {
        if (gallons == 0)
            throw 0;
        miles_per_gallon = miles / gallons; //divide zero is program crash
        //miles_per_gallon = static_cast<double> (miles) / gallons; //divide by zero is infinity 
        std::cout << "Result: " << miles_per_gallon << std::endl;
    }
    
    catch (int &ex)
    {
        std::cerr << "Sorry, can't divide by zero" << std::endl;
    }
    
	return 0;
}
