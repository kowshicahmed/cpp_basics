#ifndef I_PRINTABLE_H
#define I_PRINTABLE_H
#include <iostream>

/* this is an interface for the print function so that operator insertion can be overloaded
 * for all the inherited class members and no duplication of operation insertion is necessary
 * */

class I_Printable
{
    friend std::ostream &operator<< (std::ostream &os, const I_Printable &obj);
public:
    //this function actually runs the interface
    //the obj must have already overriden print function
    virtual void print (std::ostream &os) const = 0;
    virtual ~I_Printable () = default;
};

#endif // I_PRINTABLE_H
