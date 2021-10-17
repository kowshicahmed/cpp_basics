#include <cstring>
#include <iostream>
#include "Mystring.h"

//no-args constructor
Mystring::Mystring()
    :str{nullptr}
{
    str = new char [1];
    *str = '\0';
}

//overloaded constructor
Mystring::Mystring(const char *s)
    :str{nullptr}
{
    if (s == nullptr)
    {
        str = new char [1];
        *str = '\0';
    }
    else
    {
        str = new char [std::strlen(s)+1];
        std::strcpy(str,s);
    }
}

//copy constructor
Mystring::Mystring(const Mystring &source)
    :str{nullptr}
{
    std::cout << "copy constructor used" << std::endl;
    str = new char [std::strlen(source.str)+1];
    std::strcpy(str,source.str);
}

//move constructor
Mystring::Mystring(Mystring &&source)
    :str(source.str)
{
    source.str = nullptr;
    std::cout << "move constructor used" << std::endl;
}

//destructor
Mystring::~Mystring()
{
    delete [] str;
}

//copy assignment
Mystring &Mystring::operator= (const Mystring &rhs)
{
    std::cout << "copy assignment" << std::endl;
    
    if (this == &rhs)
        return *this;
    
    delete [] this->str;
    
    str = new char [std::strlen(rhs.str)+1];
    std::strcpy(this->str, rhs.str);
    return *this;
}

//move assignment
Mystring &Mystring::operator= (Mystring &&rhs)
{
    std::cout << "move assignment" << std::endl;
    
    if (this == &rhs)
        return *this;
    
    delete [] this->str;
    
    str = rhs.str;
    rhs.str = nullptr;          //this is important because the temp variable when destroyed will take the data with it
    return *this;
}

//Equality check
bool Mystring::operator==(const Mystring &rhs) const
{
    return (std::strcmp (this->str, rhs.str) == 0);
}

//Make lowercase
Mystring Mystring::operator-()const
{
    char *buff = new char [std::strlen(str)+1];
    std::strcpy(buff,this->str);
    for (size_t i {0}; i < std::strlen(buff); i++)
        buff[i] = std::tolower(buff[i]);
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

//concatenate
Mystring Mystring::operator+(const Mystring &rhs) const
{
    char *buff = new char [std::strlen(str)+ std::strlen (rhs.str) +1];
    std::strcpy(buff,str);
    std::strcat(buff, rhs.str);
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

//display method
void Mystring::display() const
{
    std::cout << str << ":" << get_length() << std::endl;
}

//length getter
int Mystring::get_length() const {return std::strlen(str);}

//string getter
const char *Mystring::get_str() const {return str;}