#ifndef ACCOUNT_UTIL_H
#define ACCOUNT_UTIL_H
#include <vector>
#include "Account.h"

//Utility helper functions for Account * class
void display (const std::vector <Account *> &accounts);
void deposit (std::vector <Account *> &accounts, double amount);
void withdraw (std::vector <Account *> &accounts, double amount);

#endif // ACCOUNT_UTIL_H
