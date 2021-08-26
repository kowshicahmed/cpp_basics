#include <iostream>

class I_Printable
{
    friend std::ostream &operator<< (std::ostream &os, const I_Printable &obj);
public:
    virtual void print (std::ostream &os) const = 0;
    virtual ~I_Printable () = default;
};

std::ostream &operator<< (std::ostream &os, const I_Printable &obj)
{
    obj.print(os);
    return os;
}

class Account : public I_Printable
{
public:
    virtual void withdraw(double amount)
    {
        std::cout << "In Account::withdraw" << std::endl;
    }
    virtual void print (std::ostream &os) const override
    {
        os << "Account display";
    }
    virtual ~Account() { }
};


class Checking: public Account
{
public:
    virtual void withdraw (double amount)
    {
        std::cout << "In Checking::withdraw" << std::endl;
    }
    
    virtual void print (std::ostream &os) const override
    {
        os << "Checking display";
    }
    virtual ~Checking() { }
};

class Savings: public Account
{
public:
    virtual void withdraw (double amount)
    {
        std::cout << "In Savings::withdraw" << std::endl;
    }
    
    virtual void print (std::ostream &os) const override
    {
        os << "Savings display";
    }
    virtual ~Savings() { }
};

class Trust: public Account
{
public:
    virtual void withdraw (double amount)
    {
        std::cout << "In Trust::withdraw" << std::endl;
    }
    
    virtual void print (std::ostream &os) const override
    {
        os << "Trust display";
    }
    virtual ~Trust() { }
};

void print (I_Printable &obj)
{
    std::cout << obj << std::endl;
}

int main()
{
	Account *p1 = new Account ();
    std::cout << *p1 << std::endl;
    
    Account *p2 = new Checking ();
    std::cout << *p2 << std::endl;      
    
    print(*p2);
    
//    Account a;
//    std::cout << a << std::endl;
//    
//    Checking c;
//    std::cout << c << std::endl;
//    
//    Savings s;
//    std::cout << s << std::endl;
//    
//    Trust t;
//    std::cout << t << std::endl;
//    
//	return 0;
}
