#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    :Savings_Account {name, balance, int_rate}, withdrawal_count {0}
{
}

//Deposit additional %50 bonus when amount ?= $5000
bool Trust_Account::deposit (double amount)
{
    if (amount >= bonus_threshold)
    {
        amount += bonus;
    }
    return Savings_Account::deposit (amount);
}

//Only allowed 3 withdrawals, each can be up to maximum of 20% of the account's value
bool Trust_Account::withdraw (double amount)
{
    if (withdrawal_count >= max_withdrawals || amount > (max_withdraw_percent * balance))
    {
        return false;
    }
        
    else
    {
        ++withdrawal_count ;
        return Savings_Account::withdraw (amount);
    }
}

std::ostream &operator<<(std::ostream &os, const Trust_Account &account)
{
    os << "[Trust_Account: " << account.name << ":" << account.balance << "," << account.int_rate << "%, withdrawals: " << account.withdrawal_count << "]";
    return os;
}

