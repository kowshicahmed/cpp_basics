#include <iostream>
#include <fstream>

int main()
{
    std::string filename = "stats.txt";
    std::ifstream input;

    input.open(filename);

    if(!input.is_open())
    {
        return 1;
    }

    while(input)
    {
        std::string line;
        std::getline(input, line, ':');

        int population;
        input >> population;

        //input.get();        // Discard the newline after the 1st line
        input >> std::ws;       // Same as previous line, C++11

        if(!input)      // The last newline is read in the previos line, now the buffer is empty
        {
            break;      // For this to work there has to be a newline after the last line
        }

        std::cout << line << " -- " << population << std::endl;
    }

    input.close();
    
    return 0;
}