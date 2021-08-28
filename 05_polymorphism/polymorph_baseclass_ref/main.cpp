#include <iostream>

using namespace std;

class Account 
{
public:
   //the signature of all the virtual functions should be same
   //it is best practice to put the keyword virtual before each virtual function but not mandatory
    virtual void withdraw (double amount)           
    {
        std::cout << "In Account::withdraw" << std::endl;
    }
    
    //a class with virtual functions should have virtual destructors otherwise the behaviour is undefined
    //it is best practice to put the keyword virtual before each destructor but not mandatory
    virtual ~Account ()                                     
    {
        std::cout << "Account::destructor" << std::endl;
    }
};

class Checking: public Account
{
public:
    virtual void withdraw (double amount)
    {
        std::cout << "In Checking::withdraw" << std::endl;
    }
    
    ~Checking ()
    {
        std::cout<< "Checking::destructor" << std::endl;
    }
};

class Savings: public Account
{
public:
    virtual void withdraw (double amount)
    {
        std::cout << "In Savings::withdraw" << std::endl;
    }
    
    ~Savings ()
    {
        std::cout << "Savings::destructor" << std::endl;
    }
};

class Trust: public Account
{
public:
    virtual void withdraw (double amount)
    {
        std::cout << "In Trust::withdraw" << std::endl;
    }
    ~Trust ()
    {
        std::cout << "Trust::destructor" << std::endl;
    }
};


void do_withdraw (Account &account, double amount)
{
    account.withdraw (amount);
}
int main(int argc, char **argv)
{
	Account a;
    Account &ref = a;
    ref.withdraw (1000);        // In Account::withdraw
    
    Trust t;
    Account &ref1 = t;
    ref1.withdraw (1000);       // In Trust::withdraw
    
    Account a1;
    Savings a2;
    Checking a3;
    Trust a4;
    
    do_withdraw (a1, 1000);     // In Account::withdraw
    do_withdraw (a2,2000);      // In Savings::withdraw
    do_withdraw (a3, 3000);     // In Checking::withdraw
    do_withdraw (a4, 4000);     // In Trust::withdraw
    
	return 0;
}
