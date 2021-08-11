#include <iostream>
#include <iomanip> // Must include for manipulators

int main()
{
	double num1 {123456789.987654321};
    double num2{1234.5678};
    double num3{1234.0};
    
    // Using default settings
    std::cout << "---- Defaults -----------------------" << std::endl;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;
    
    // Note how since we can't display in precision 2 scientific is used
    std::cout << std::setprecision (2);
    std::cout << "----Precision 2-------------------" << std::endl;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;
    
    // Using precision 5
    std::cout << std::setprecision (5);
    std::cout << "----Precision 5-------------------" << std::endl;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;
    
    // Using precision 9
    std::cout << std::setprecision (9);
    std::cout << "----Precision 9-------------------" << std::endl;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;
    
     // Using precision 3 and fixed
    std::cout << std::setprecision (3) << std::fixed;
    std::cout << "----Precision 3 - Fixed -------------------" << std::endl;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;
    
    // Using precision 3 and fixed
    std::cout << std::setprecision (3) << std::scientific;
    std::cout << "----Precision 3 - Fixed - Scientific -------------------" << std::endl;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;
    
    // Using precision 3 and fixed and uppercase
    std::cout << std::setprecision (3) << std::scientific << std::uppercase;
    std::cout << "----Precision 3 - Fixed - Scientific - Upper case  -------------------" << std::endl;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;
    
    // Using precision 3 and fixed and show pos
    std::cout << std::setprecision (3) << std::showpos;
    std::cout << "----Precision 3 - Fixed - Scientific - Upper case  -------------------" << std::endl;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;
    
    //back to defaults
    std::cout.unsetf(std::ios::scientific | std::ios::fixed);
    std::cout << std::resetiosflags(std::ios::showpos);
    
    // Show trailing zeros up to precision 10
    std::cout << std::setprecision(10) << std::showpoint;
    std::cout << "----Precision 10 - Show point  -------------------" << std::endl;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;
    
    //Back to defaults
    std::cout.unsetf (std::ios::scientific | std::ios::fixed);
    std::cout << std::setprecision(6);
    std::cout << std::resetiosflags (std::ios::showpos);
    std::cout << std::resetiosflags(std::ios::showpoint);
    
    // Back to default
    std::cout << "---- Back to Defaults -----------------------" << std::endl;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;
    
	return 0;
}
