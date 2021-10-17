#include <iostream>
#include <vector>

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

int main(int argc, char **argv)
{
	std::cout << "\n === Pointers ===" << std::endl;
    Account *p1= new Account ();
    Account *p2 = new Savings ();       //this is valid since Savings is an Account, so p2 can hold the address of savings due to is-a relationship
    Account *p3 = new Checking ();
    Account *p4 = new Trust ();
    
    p1->withdraw (1000);
    p2->withdraw (1000);
    p3->withdraw (1000);
    p4->withdraw (1000);
    
    std::cout << "\n === Array ===" << std::endl;
    Account *array [] = {p1,p2,p3,p4};
    for (auto i = 0; i < 4; ++i)
        array [i]->withdraw (1000);
    
    std::cout << "\n ===Vector ===" << std::endl;
    std::vector <Account *> accounts {p1, p2, p3, p4};
    for (auto acc_ptr: accounts)
        acc_ptr->withdraw (1000);
    
    std::cout << "\n === Clean up ===" << std::endl;
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    
    
	return 0;
}
