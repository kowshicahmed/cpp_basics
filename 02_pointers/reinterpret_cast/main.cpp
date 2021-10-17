#include <iostream>

// It can perform dangerous conversions 
// because it can typecast any pointer to any other pointer

class Mango
{
    int mango_quantity;
public:
    Mango(int n)
        : mango_quantity{n} {}
    void eatMango(int n)
    {
        std::cout << "Eating Mango" << std::endl;
    }
    void print_quantity()
    {
        std::cout << "Mango qty: " << mango_quantity << std::endl;
    }
};

class Banana
{
    int banana_quantity;
public:
    Banana(int n)
        : banana_quantity{n} {}
    void eatBanana()  
    {
        std::cout << "Eating Banana" << std::endl;
    }
    void print_quantity()
    {
        std::cout << "Banan qty: " << banana_quantity << std::endl;
    }
};


// it is often used while working with bits
// note there are 2 padding bytes at the end or in between of the struct depending on the system
// that's why reinterpret_cast is not good for porting project to a different system
struct myStruct 
{
    int x;
    int y;
    char c;
    bool b;
};

int main()
{
    // Example with class
    Banana *ban = new Banana(10);
    Mango *man = new Mango(20);
    Banana *newbanana = reinterpret_cast<Banana *>(man); 
    newbanana->eatBanana();
    newbanana->print_quantity();
    
    // Example with struct
    myStruct obj;
    obj.x = 5;
    obj.y = 10;
    obj.c = 'a';
    obj.b = true;

    int *ptr = reinterpret_cast<int*>(&obj);
    std::cout << *ptr << std::endl; 
    
    ptr++;
    std::cout << *ptr << std::endl;
    
    ptr++;
    char *c = reinterpret_cast<char*>(ptr);
    std::cout << *c << std::endl;

    std::cout << *(reinterpret_cast<bool*>(++c));

    return 0;
}