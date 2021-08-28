#include <iostream>
#include <iomanip> // Must include for manipulators

int main()
{
	std::cout << "noboolalpha - default (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "noboolalpha - default (10 == 20): " << (10 == 20) << std::endl;
    
    // Set to true/false formatting
    std::cout << std::boolalpha;    // Change to true/false
    std::cout << "boolalpha - (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "boolalpha - (10 == 20): " << (10 == 20) << std::endl;
    
    // Setting stays for future boolean insertion
    std::cout << "boolalpha - (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "boolalpha - (10 == 20): " << (10 == 20) << std::endl;
    
    // Toggle to nobolean
    std::cout << std::noboolalpha;    // Change to 0/1
    std::cout << "noboolalpha - (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "noboolalpha - (10 == 20): " << (10 == 20) << std::endl;
    
    // Set back to true/false using setf method
    std::cout.setf(std::ios::boolalpha); // Std is the namespace, ios is the class and boolalpha is the flag
    std::cout << "boolalpha - (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "boolalpha - (10 == 20): " << (10 == 20) << std::endl;
    
    // Resets to default which is 0/1
    std::cout << std::resetiosflags (std::ios::boolalpha);
    std::cout << "noboolalpha - default (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "noboolalpha - default (10 == 20): " << (10 == 20) << std::endl;
    
	return 0;
}
