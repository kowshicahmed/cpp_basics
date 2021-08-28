#include <iostream>
#include <deque>
#include <cctype>
#include <iostream>
#include <vector>
#include <iomanip>

//> Template function to display any deque
template <typename T>
void display (const std::deque <T> &d)
{
    std::cout << "[";
    for (const auto &elem: d)
        std::cout << elem << " ";
    std::cout << "]" << std::endl;
}

//> a function to check if a string is palindrome
bool is_palindrome(const std::string &s)
{
    
    std::deque <char> d1;
    std::deque <char> d2;
    for (const auto &c: s)
    {
        if (isalpha(c))
            d1.push_front(std::toupper(c));
    }
    for (const auto &c: s)
    {
        if (std::isalpha(c))
            d2.push_back(std::toupper(c));
    }
    if(d1==d2)
        return true;
    return false;
}

//> another way, which checks the fron and end of the deque and remove the item if they are equal
//> if at the end we are left with zero or only one item then the string is a palindrome
bool is_palindrome2(const std::string &s)
{
    std::deque<char> d;
    
    // add all the string characters that are alpha to the back of the deque in uppercase
    for(char c : s)
    {
        if(std::isalpha(c))
            d.push_back(std::toupper(c));
    }
        char c1{};
        char c2{};
        
        while(d.size() > 1)
        {
            c1 = d.front();
            c2 = d.back();
            d.pop_front();
            d.pop_back();
            if(c1 != c2)
                return false;
        }
        return true;
}

int main(int argc, char **argv)
{
	std::vector <std::string> test_strings {"a", "aa", "aba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
                                                                "avid diva", "Amore, Roma", "C++"};
	
    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    
    for(const auto &s: test_strings)
    {
        std::cout << std::setw(8) << std::left << is_palindrome(s) << s << std::endl;
    }
    
    std::cout << std::endl;
    return 0;
}
