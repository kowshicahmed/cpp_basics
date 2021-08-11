#include <iostream>
#include <string>

class DivideByZeroException 
{
};

class NegativeValueException
{
};


double calculate_mpg (int miles, int gallons)
{
    if (gallons == 0)
        throw DivideByZeroException ();             //throw expection object
    if (miles < 0 || gallons < 0)
        throw NegativeValueException ();        //throw expection object
    return static_cast <double> (miles) / gallons;
}

int main(int argc, char **argv)
{
	int miles {};
    int gallons {};
    double miles_per_gallon {};
    
    std::cout << "Enter the miles: ";
    std::cin >> miles;
    std::cout << "Enter the gallons: ";
    std::cin >> gallons;
    
    try
    {
        miles_per_gallon = calculate_mpg(miles, gallons);
        std::cout << "Result: " << miles_per_gallon << std::endl;
    }
    catch (DivideByZeroException &ex)
    {
        std::cerr << "Tried to divide by zero" << std::endl;
    }
    catch (NegativeValueException &ex)
    {
        std::cerr <<  "Sorry one of your parameters is negative" << std::endl;
    }
   //catch (...) { } //catch all handeler
    std::cout<< "Bye" << std::endl;
    
	return 0;
}
