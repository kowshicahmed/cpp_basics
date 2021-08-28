#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H
#include "Account.h"

class Checking_Account : public Account
{
    friend std::ostream &operator<< (std::ostream &os, const Checking_Account &account);
private:
    static constexpr const char *def_name = "Unnammed Checking Account";
    static constexpr double def_balance = 0.0;
    static constexpr double fee = 1.50;
    
public:
    Checking_Account (std::string name = def_name, double balance = def_balance);
    bool withdraw(double amount);
    //Deposit will be inherited

};

#endif // CHECKING_ACCOUNT_H
