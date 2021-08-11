#include <iostream>
#include <vector>
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std;

int main(int argc, char **argv)
{
    //Account joe; //error because Account is now an abstract class
    
//    Checking_Account c;
//    cout << c << endl;
//    
//    Savings_Account s {"Frank", 5000, 2.6};
//    cout << s << endl;
//    s.deposit (10000);
//    cout << s << endl;
//    s.withdraw (10000);
//    cout << s << endl;
    Checking_Account frank {"Frank", 5000};
    cout << frank << endl;
    
    Account *trust = new Trust_Account ("Leo", 10000, 2.6);
    cout << *trust << endl;
    
    Account *p1 = new Checking_Account ("Larry", 10000);
    Account *p2 = new Savings_Account ("Moe", 1000);
    Account *p3 = new Trust_Account ("Curly");
    
    std::vector <Account *> accounts {p1, p2, p3};
    
    display (accounts);
    deposit (accounts, 1000);
    withdraw (accounts, 2000);
    
    display (accounts);
    
    delete p1;
    delete p2;
    delete p3;
    delete trust;
  
	return 0;
}
