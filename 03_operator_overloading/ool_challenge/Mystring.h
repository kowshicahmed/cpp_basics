#ifndef MYSTRING_H
#define MYSTRING_H

class Mystring
{
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    friend std::istream &operator>>(std::istream &is, Mystring &rhs);
private:
    char *str; //pointer to a char[] that holds a C-style string
    
public:
    Mystring();                                 //no-args constructor
    Mystring(const char *s);                    //overloaded constructor
    Mystring(const Mystring &source);           //copy constructor
    Mystring(Mystring &&source);                //move constructor
    ~Mystring();                                //destructor
    
    Mystring &operator= (const Mystring &rhs);  //copy assignment
    Mystring &operator= (Mystring &&rhs);       //move assignment
    
    Mystring operator-() const;                         //make lowecase
    Mystring operator+(const Mystring &rhs) const;      //concatenate
    bool operator==(const Mystring &rhs) const;         //equality check
    bool operator<(const Mystring &rhs) const;          //less than check
    bool operator>(const Mystring &rhs) const;          //greater than check
    Mystring operator*(int &&rhs) const;                //s="ab", s*2 ="abab" 
    Mystring &operator+= (const Mystring &rhs);         //s1+=s2
    
    void display() const;
    int get_length() const;                     //getters
    const char *get_str() const;

};

#endif // MYSTRING_H
