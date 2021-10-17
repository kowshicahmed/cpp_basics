#ifndef TRUST_ACCOUNT_H
#define TRUST_ACCOUNT_H
#include "Savings_Account.h"

class Trust_Account : public Savings_Account
{

    friend std::ostream &operator<< (std::ostream &os, const Trust_Account &account);    
private:
    static constexpr const char *def_name = "Unnammed Trust Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
    static constexpr double bonus = 50.00;
    static constexpr double bonus_threshold = 5000.0;
    static constexpr int max_withdrawals = 3;
    static constexpr double max_withdraw_percent = 0.2;
    
protected:
    
    int withdrawal_count;

public:
    Trust_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
    
    bool deposit (double amount);
    bool withdraw (double amount);
    
    double get_bonus () {return bonus;}
    int get_withdrawal_count () {return withdrawal_count;}
    void incr_withdrawal_count () {withdrawal_count++;}

};

#endif // TRUST_ACCOUNT_H
