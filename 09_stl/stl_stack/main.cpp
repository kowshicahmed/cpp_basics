#include <iostream>
#include <stack>
#include <vector>
#include <list>

// Stack is a LIFO
// This function displays a stack 
// by repeatedly topping and popping the stack
// Note that the stack is passed in value so we
// don't affect the passed stack

template <typename T>
void display(std::stack<T> s)
{
    std::cout << "[ ";
    while (!s.empty())
    {
        T elem = s.top();
        s.pop();
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}

int main(int argc, char **argv)
{
	std::stack<int> s;
    std::stack<int, std::vector<int>> s1;
    std::stack<int, std::list<int>> s2;
    std::stack<int, std::deque<int>> s3;
    
    for (int i: {1,2,3,4,5})
        s.push(i);
    display(s);
    
    s.push(100);
    display(s);
    
    s.pop();
    s.pop();
    display(s);
    
    while(!s.empty())           // there is no clear method so this is how we clear stack
        s.pop();
    display(s);
    
    std::cout << "Size: " << s.size() << std::endl;
    
    s.push(10);
    display(s);
    
    s.top() = 100;              // change the top = 10 to 100 
    display(s);
    
	return 0;
}
