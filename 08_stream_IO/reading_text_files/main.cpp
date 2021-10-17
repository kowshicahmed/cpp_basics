#include <iostream>
#include <fstream>

int main()
{
    std::string inFileName = "test.txt";

    std::ifstream inFile;

    inFile.open(inFileName);

    if(inFile.is_open())
    {
        std::string line;
        // getline (inFile, line); // This will get a single line from the file
        // std::cout << line << std::endl;
        // inFile >> line;         // This will stop at the first space
        // std::cout << line << std::endl;

        while (!inFile.eof())     // This will read all the lines, only (inFile) will also work as "!" operator is overloaded
        {
            getline(inFile, line);
            std::cout << line << std::endl;
        }
        
        
        inFile.close();
    }

    else
    {
        std::cout << "Can not open file: " << inFileName << std::endl;
    }
}