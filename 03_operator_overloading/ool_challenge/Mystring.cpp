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
    //std::cout << "constructor called" << std::endl;
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

//less than check
bool Mystring::operator<(const Mystring &rhs) const
{
    return (std::strcmp (this->str, rhs.str) < 0 ? true : false);
}

//greater than check
bool Mystring::operator>(const Mystring &rhs) const
{
    return (std::strcmp (this->str, rhs.str) > 0 ? true : false);
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

//overloaded insertion
std::ostream &operator<<(std::ostream &os, const Mystring &rhs)
{
    os << rhs.str;
    return os;
}

//extraction
std::istream &operator>>(std::istream &is, Mystring &rhs)
{
    char *buff = new char [1000];
    is >> buff;
    rhs = Mystring {buff};
    delete [] buff;
    return is;
}

//multiplication
Mystring Mystring::operator*(int &&rhs) const
{
    /*
    char *buff = new char [(std::strlen(str)*rhs)+1];
    char *temp_buff = new char [std::strlen(str)+1];
    std::strcpy(buff,this->str);
    std::strcpy(temp_buff,this->str);
    for (int i {1}; i < rhs; i++)
        std::strcat(buff, temp_buff);
    Mystring temp {buff};
    delete [] buff;
    delete [] temp_buff;
    return temp;
    */
    Mystring temp;
    for (int i {1}; i <= rhs; i++)
        temp = temp + *this; //using overloaded concat
    return temp;
}

Mystring &Mystring::operator+= (const Mystring &rhs)
{
    /*
    char *buff = new char [std::strlen(str)+1];
    std::strcpy(buff, this->str);
    delete [] this->str;
    str = new char [std::strlen(buff) + std::strlen(rhs.str)+1];
    std::strcpy(this->str, buff);
    std::strcat(this->str, rhs.str);
    delete [] buff;
    return *this;
    */
    *this = *this + rhs; //using the overloaded concat operator
    return *this;

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