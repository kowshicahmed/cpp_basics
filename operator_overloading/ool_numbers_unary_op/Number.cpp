#include "Number.h"
#include <iostream>

Number::Number()
    :number{0}
{
    
}

Number::Number(int a)
    :number{a}
{
    
}

Number::~Number()
{
}

Number Number::operator-() const
{
    return -(this->number);
}

Number Number::operator++()
{
    return ++(this->number);
}

void Number::display () const
{
    std::cout << "The number is: " << this->number << std::endl;
}
