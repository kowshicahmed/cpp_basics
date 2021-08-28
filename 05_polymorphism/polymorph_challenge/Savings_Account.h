#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H
#include "Account.h"

//savings account is a type of Account
//add an interest rate
//withdraw- same as a regular account
//deposit:
//      amount supplide to deposit will be incremented by (amount * int_rate/100)
//      and then the updated amount will be deposited

class Savings_Account : public Account
{
private:
    static constexpr const char *def_name = "Unnammed Savings Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;

protected:
    double int_rate;
public:
    
    Savings_Account (std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
    virtual bool deposit (double amount) override;
    virtual bool withdraw (double amount) override;
    
    virtual void print (std::ostream &os) const override;
    
    virtual ~Savings_Account () = default;
};

#endif // SAVINGS_ACCOUNT_H
