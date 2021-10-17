#include <iostream>
#include "Savings_Account.h"

using namespace std;

int main(int argc, char **argv)
{
	cout << "\n======= Account class ========" << endl;
    Account a1{1000.0};
    cout << a1 << endl;     //Account balance 1000
    
    a1.deposit(500.0);
    cout << a1 << endl;     //Account balance 1500
    
    a1.withdraw(1000);
    cout << a1 << endl;     //Account balance 500
    
    a1.withdraw(5000.0);    //insufficient funds
    cout << a1 << endl;     //Account balance 500
    
    cout << "\n====== Savings Account class =======" << endl;
    Savings_Account s1 {1000.0, 5.0};
    cout << s1 << endl;     //Savings account balance 1000, interest rate 5
    
    s1.deposit(1000);
    cout << s1 << endl;     //Savings account balance 2050, interest rate 5
    
    s1.withdraw(2000);
    cout << s1 << endl;     //Savings account balance 50, interest rate 5
    
    s1.withdraw(1000);      //Insufficient funds
    cout << s1 << endl;
	return 0;
}
