#include <iostream>
#include <queue>           

class Person
{
    friend std::ostream &operator<<(std::ostream &os, const Person &p);
    std::string name;
    int age;
public:
    Person() : name{"Unknown"}, age{0} {}
    Person(std::string name, int age)
        : name{name}, age{age} {}
    bool operator<(const Person &rhs) const         // priority queue uses this operator to sort
    {
        return this->age < rhs.age;                     // we can also sort by name if we want
    }
    bool operator==(const Person &rhs) const
    {
        return (this->name == rhs.name && this->age == rhs.age);
    }
};

std::ostream &operator<<(std::ostream &os, const Person &p)
{
    os << p.name << ":" << p.age;
    return os;
}

// This function displays a priority_queue
// by repeatedly topping and popping the priority_queue
// Note that the pq is passed in value so we
// don't affect the passed pq
template <typename T>
void display(std::priority_queue<T> pq)
{
    std::cout << "[ ";
    while (!pq.empty())
    {
        T elem = pq.top();
        pq.pop();
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}

void test1()
{
    std::cout << "\nTest1 ====================================" << std::endl;
    
    std::priority_queue<int> pq;
    for (int i : {3,5,7,12,23,12,4,100,0,3,5,7})            // it is ok to push duplicates
        pq.push(i);
        
    std::cout << "Size: " << pq.size() << std::endl;
    std::cout << "Top: " << pq.top() << std::endl;          // the highest value is at the top
    
    display(pq);
    pq.pop();
    display(pq);
}

void test2()
{
    std::cout << "\nTest2 ====================================" << std::endl;
    
    std::priority_queue<Person> pq;
    pq.push(Person{"A", 10});
    pq.push(Person{"B", 1});
    pq.push(Person{"C", 14});
    pq.push(Person{"D", 18});
    pq.push(Person{"E", 7});
    pq.push(Person{"F", 27});
    
    display(pq);
}

int main(int argc, char **argv)
{
	test1();
    test2();
    
	return 0;
}
