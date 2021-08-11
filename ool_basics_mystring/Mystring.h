#ifndef MYSTRING_H
#define MYSTRING_H

class Mystring
{
private:
    char *str; //pointer to a char[] that holds a C-style string
    
public:
    Mystring();                         //no-args constructor
    Mystring(const char *s);            //overloaded constructor
    Mystring(const Mystring &source);   //copy constructor
    ~Mystring();                        //destructor
    void display() const;
    int get_length() const;             //getters
    const char *get_str() const;

};

#endif // MYSTRING_H
