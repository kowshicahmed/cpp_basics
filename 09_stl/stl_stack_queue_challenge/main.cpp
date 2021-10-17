#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <iomanip>

//> a function to check if a string is palindrome
bool is_palindrome(const std::string &s)
{
    
    std::queue <char> q;
    std::stack <char> st;
    for (const auto &c: s)
    {
        if (std::isalpha(c))
        {
            q.push(std::toupper(c));
            st.push(std::toupper(c));
        }
    }
    while (!q.empty())
    {
        if (q.front() != st.top())
            return false;
        q.pop();
        st.pop();
    }
    return true;
}

int main(int argc, char **argv)
{
	std::vector <std::string> test_strings {"a", "aa", "aba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
                                                                "avid diva", "Amore, Roma", "C++", "A Toyota's a toyota", "Rear"};
	
    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    
    for(const auto &s: test_strings)
    {
        std::cout << std::setw(8) << std::left << is_palindrome(s) << s << std::endl;
    }
    
    std::cout << std::endl;
	return 0;
}
