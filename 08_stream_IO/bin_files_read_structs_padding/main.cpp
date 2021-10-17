#include <iostream>
#include <string>
#include <fstream>

// C++ adds pad to structs to make them more efficient
// if we want to take the struct and write it in a file we need to turn off padding
// Allign the follwing data structure in single byte boundries (padding)
#pragma pack(push, 1)       // this has a stack like stucture, turn off padding
struct Person
{
// string wont work here because string class containes pointers
// the text is not acutally stored in the string variable
// string uses heap to allocate memory
    char name[50];  // string wont work here
    int age;
    double height;
};
#pragma pack(pop)   // turn on padding

int main()
{
    //std::cout << sizeof(Person) << std::endl;   // Without pragma pack, it will show 2 bytes more
    Person someone = {"Frodo", 220, 0.8};
    std::string fileName = "test.bin";
    
/*************************************** Write binary file**********************************/
    std::ofstream outputFile;
    // it is important to mention here that the filetype is binary
    // binary files do not have something line new lines etc
    outputFile.open(fileName, std::ios::binary);

    //outputFile.open(fileName, std::ios::binary|std::ios::out); // if we use fstream insted of ofstream
    if(outputFile.is_open())
    {
        // reinterpret_cast converts a pointer type to another pointer type
        // this conversion is dangerous to use
        // it is often used while working with bits
        outputFile.write(reinterpret_cast<char* > (&someone), sizeof(Person));
        outputFile.close();
    }
    else
    {
        std::cout << "Could not create file " + fileName << std::endl;
    }


/************************************* Read binary file **********************************/
    Person someoneElse = {};
    std::ifstream inputFile;
    inputFile.open(fileName, std::ios::binary);

    //outputFile.open(fileName, std::ios::binary|std::ios::out); // if we use fstream insted of ofstream
    if(inputFile.is_open())
    {
        inputFile.read(reinterpret_cast<char* > (&someoneElse), sizeof(Person));
        inputFile.close();
    }
    else
    {
        std::cout << "Could not create file " + fileName << std::endl;
    }

    std::cout << someoneElse.name << ", " << someoneElse.age << ", " << someoneElse.height << std::endl;
    
    return 0;
}