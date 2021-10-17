#include <iostream>

int main()
{
    int d = -12;
    int16_t e {};
    uint16_t a = 1;
    uint16_t b = 2;
    uint32_t c = ((a << 16) | b);
    std::cout << c << std::endl;
    a = d;
    std::cout << a << std::endl;
    e = a;
    std::cout << e << std::endl;


}