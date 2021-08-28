#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H
#include "Account.h"

class Savings_Account: public Account //public inheritance=is a relationship
{
public:
    double int_rate;
    Savings_Account();
    ~Savings_Account();
    void deposit (double amount);
    void withdraw (double amount);
};

#endif // SAVINGS_ACCOUNT_H
