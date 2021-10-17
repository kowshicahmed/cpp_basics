#include <iostream>
#include <fstream>

int main()
{
    //std::ofstream outFile;
    // we can also use fstream then we have to specify that the file is output
    std::fstream outFile;

    std::string outputFileName = "text.txt";

    //outFile.open(outputFileName);
    outFile.open(outputFileName, std::ios::out);

    if(outFile.is_open())
    {
        outFile << "Hello there" << std::endl;
        outFile << 1234 << std::endl;
        outFile.close();
    }

    else
    {
        std::cout << "Could not create file: " << outputFileName << std::endl;
    }



    
    
    return 0;
}