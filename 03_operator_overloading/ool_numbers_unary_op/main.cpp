#include <iostream>
#include "Number.h"

using namespace std;

int main(int argc, char **argv)
{
	Number my_number (100);
    my_number.display();
    Number n2 = -my_number;
    n2.display();
    Number n3 = ++my_number;
    n3.display();
	return 0;
}
