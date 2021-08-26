#include <iostream>
#include <vector>

/* * Basics of function definition and calling
 *   Includes pass by value, default arguments, function overloading, global variables
 *  */

using namespace std;

/********** Function Prototypes ***************/
double calc_area_circle(double radius);
void area_circle();

//> Examples for pass by value
void pass_by_value_string(string s);
void pass_by_value_vector(vector<string> v);
void print_vector(vector<string> v);

//> Example of default arguments
/* Can add multiple default arguments
 *  Default argument should be tail-ended
 *  Ex: The first argument can't have default value if the other
 *  two arguments don't have default values for a 3 argument function
 */
double calc_cost(double base_cost, double tax_rate);                //> Without default argument
double calc_cost_default(double base_cost, double tax_rate = 0.06); //> With default argument

//> Example of function overloading
int add_numbers(int a, int b);
double add_numbers(double a, double b);
void print(int);
void print(double);
void print(string);
void print(vector<string>);

/********** Constants and global variables ***************/
const double pi{3.14159};

/********** Main method ***************/
int main(int argc, char **argv)
{
    //> Example of pass by value
    area_circle();
    string name{"Akash"};
    cout << "String before pass by value:" << name << endl;
    pass_by_value_string(name); //> This does not change the value of name
    cout << "String after pass by value:" << name << endl;

    vector<string> v{"akash", "batash", "patal"};
    print_vector(v);
    pass_by_value_vector(v); //> This also does not change the value of vector v
    print_vector(v);

    //> Example of default argument
    double cost{10};
    cost = calc_cost(100.0, 0.06);
    cost = calc_cost_default(200.0);       //> Will use the default tax value
    cost = calc_cost_default(100.0, 0.08); //> Will use 0.08 not the default

    //> Example of function overloading
    cout << add_numbers(1, 2) << endl;
    cout << add_numbers(10.5, 2.6) << endl;

    vector<string> names{"larry", "moe", "curly"};
    print(names);
    print("Kowshic ahmed");

    return 0;
}

/********** Helper Functions ***************/
//> Basic function examples
double calc_area_circle(double radius)
{
    return pi * radius * radius;
}

void area_circle()
{
    double radius{};
    cout << "\nEnter the radius of the circle:";
    cin >> radius;
    cout << "The area of the circle with radius " << radius << " is " << calc_area_circle(radius) << endl;
}

//> Pass by value examles
void pass_by_value_string(string s)
{
    s = "changed"; //> It changes only the local copy s, variable in main is unchanged
}

void pass_by_value_vector(vector<string> v)
{
    v.clear();
}

void print_vector(vector<string> v)
{
    for (auto s : v)
    {
        cout << s << " "; //> Add a space after first string
    }
    cout << endl;
}

double calc_cost(double base_cost, double tax_rate)
{
    return base_cost += (base_cost * tax_rate);
}

double calc_cost_default(double base_cost, double tax_rate) //> No need to add the default value here
{
    return base_cost += (base_cost * tax_rate);
}

//> Function overloading examples
int add_numbers(int a, int b)
{
    return a + b;
}

double add_numbers(double a, double b)
{
    return a + b;
}

void print(int num)
{
    cout << "Printing int:" << num << endl;
}

void print(double num)
{
    cout << "Printing double:" << num << endl;
}

void print(string name)
{
    cout << "Printing string:" << name << endl;
}

void print(vector<string> names)
{
    cout << "The names are:";
    for (auto c : names)
        cout << c << " ";

    cout << endl;
}