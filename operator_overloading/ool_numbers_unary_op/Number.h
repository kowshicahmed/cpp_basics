#ifndef NUMBER_H
#define NUMBER_H

class Number
{
private:
    int number;
    
public:
    //constructor
    Number();
    Number(int a);
    //destructor
    ~Number();
    
    //operator overloading
    Number operator-() const;
    Number operator++();
    
    //member functions
    void display () const;

};

#endif // NUMBER_H
