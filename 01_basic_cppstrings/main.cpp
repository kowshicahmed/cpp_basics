#include <iostream>
#include <string>

/* * Basic functions and operations of cpp strings
 * * Such as concatenation, array type access, comparing, extracting, length of string etc.
 *  */

using namespace std;

int main(int argc, char **argv)
{
    /********** Initializations ***************/
    string s1;             //< Initializing empty string
    string s2{"Akash"};    //< Initialized to Akash
    string s3{s2};         //< Copy s2 to s3
    string s4{"Akash", 3}; //< Aka
    string s5{s3, 0, 2};   //< Ak copy s3 from index 0 to 1
    string s6(3, 'X');     //< XXX

    /********** Displaying ***************/
    cout << "Assignment" << endl;
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
    cout << s5 << endl;
    cout << s6 << endl;

    /********** Assignment ***************/
    string s7;
    s7 = "C++ rocks"; //< This is also possible unlike C
    cout << s7 << endl;
    string s8{"Hello"};
    s8 = s7;
    cout << s8 << endl;

    /********** String concatenation in C++ strings ***************/
    cout << "Concatenation" << endl;
    string part1{"C++"};
    string part2{"is powerful"};

    string sentence;
    sentence = part1 + " " + part2 + " language";
    cout << sentence << endl;

    /********** Accessing characters usit at() method ***************/
    cout << "Accessing using at method" << endl;
    cout << s2[0] << endl;
    cout << s2.at(0) << endl;

    /********** Array type assignment or using at method ***************/
    cout << "Assignment using at() method or array method" << endl;
    s2[0] = 'f';
    cout << s2.at(0) << endl;
    s2.at(0) = 'g';
    cout << s2.at(0) << endl;

    /********** Accessing characters using range based for loop ***************/
    cout << "Accessing using range based for loop" << endl;
    s2 = "Water Melon";
    for (char c : s2)
        cout << c << endl;

    for (size_t i{0}; i < s2.length(); ++i)
        cout << s2.at(i);
    cout << endl;

    /********** Comparing strings ***************/
    s1 = "Apple";
    s2 = "Banana";
    cout << (s1 < s2) << endl;       //< true
    cout << (s1 > s2) << endl;       //< false
    cout << (s1 == "Apple") << endl; //< true

    /********** Extracting substrings ***************/
    s1 = "This is a test";
    cout << s1.substr(0, 4) << endl; //< this
    cout << s1.substr(5, 2) << endl; //< is

    /********** Searching strings ***************/
    string user_word{};
    cin >> user_word;
    size_t position = s1.find(user_word);
    if (position != string::npos)
        cout << "Found at pos: " << position << endl; //< Returns the index of the string
    else
        cout << "Could not find" << endl; //< The search will start from index 4

    /********** Erasing and clearing string ***************/
    cout << s1.erase(0, 5) << endl; //< is a test
    s1.clear();                     //< Empty string
    cout << s1 << endl;

    /********** Length of a string ***************/
    s1 = "Frank";
    cout << s1.length() << endl; //< 5

    /********** Compound concatenation ***************/
    s1 += " James";
    cout << s1 << endl; //< Frank James

    /********** Getting string input ***************/
    string s9;
    // cin >> s9;               //< Spaces discarded
    // cout << s9 << endl;
    // getline(cin, s9);        //< Read entire line until enter is pressed
    // cout << s9 << endl;
    getline(cin, s9, 'x');      //< Stops reading when the user presses 'x'
    cout << s9 << endl;

    return 0;
}
