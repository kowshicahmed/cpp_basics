#include <iostream>

enum class Color {red, green, blue};

void show_color (Color c)
{
    switch (c)
    {
    case Color::red:
        std::cout << "red" << std::endl;
        break;
    case Color::blue:
        std::cout << "blue" << std::endl;
        break;
    case Color::green:
        std::cout << "green" << std::endl;
        break;    
    default:
        break;
    }
}

int main()
{
    show_color(Color::red);

    return 0;
}