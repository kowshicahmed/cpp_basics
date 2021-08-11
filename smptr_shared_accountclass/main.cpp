#include <iostream>
#include <memory>
#include <vector>

#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

class Test
{
private:
    int data;
public:
    Test () : data {0} {std::cout << "Test constructor (" << data << ")" << std::endl; }
    Test (int data) : data {data} {std::cout << "Test constructor (" << data << ")" << std::endl;}
    
    int get_data () const {return data;}
    ~Test () {std::cout << "Test destructor (" << data << ")" << std::endl;}
};

void func (std::shared_ptr <Test> p)
{
    std::cout << "Use count: " << p.use_count() << std::endl;   //since p is a copy of ptr, use_count is 2
}


int main()
{
    std::shared_ptr<Test> ptr = std::make_shared <Test> (100);
    func(ptr); //a copy of ptr is created
    std::cout << "Use count: " << ptr.use_count () << std::endl; //use_count is 1 since the copy (p) is out of scope
    //new scope
    {
        std::shared_ptr <Test> ptr1 = ptr;
        std::cout << "Use count: " <<ptr.use_count () << std::endl;
        {
            std::shared_ptr <Test> ptr2 = ptr;
            std::cout << "Use count: " << ptr.use_count () << std::endl;
            ptr.reset ();
        }
        std::cout << "Use count: " << ptr.use_count() << std::endl;
    }
    std::cout << "Use count: " << ptr.use_count () << std::endl;
    
    std::cout << "\n====================================" << std::endl;
    
    std::shared_ptr<Account> acc1 = std::make_shared <Trust_Account> ("Larry", 10000, 3.1);
    std::shared_ptr<Account> acc2 = std::make_shared <Checking_Account> ("Moe", 5000);
    std::shared_ptr<Account> acc3 = std::make_shared <Savings_Account> ("Curly", 6000);
    
    std::vector <std::shared_ptr<Account>> accounts;
    accounts.push_back (acc1);
    accounts.push_back (acc2);
    accounts.push_back (acc3);
    
    for (const auto &acc: accounts)
        {
            std::cout << *acc << std::endl;
            std::cout << "Use count: " << acc.use_count () << std:: endl;
        }
    
    
    
	return 0;
}
