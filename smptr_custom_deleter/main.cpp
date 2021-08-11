#include <iostream>
#include <memory>

class Test
{
private:
    int data;
public:
    Test () : data {0} {std::cout << "\tTest constructor (" << data << ")" << std::endl; }
    Test (int data) : data {data} {std::cout << "\tTest constructor (" << data << ")" << std::endl;}
    
    int get_data () const {return data;}
    ~Test () {std::cout << "\tTest destructor (" << data << ")" << std::endl;}
};

void my_deleter(Test *ptr)
{
    std::cout << "\tUsing my custom function deleter" << std::endl;
    delete ptr;
}

int main(int argc, char **argv)
{
	{
        //using a function
        std::shared_ptr<Test> ptr1 {new Test{100}, my_deleter}; //can't use make shared
    }
    
    std::cout << "===============" << std::endl;
    {
        //using lambda expression
        std::shared_ptr<Test> ptr2 (new Test{1000},
            [] (Test *ptr) {
                std::cout << "\tUsing my custom lambda deleter" << std::endl;
                delete ptr;
            });
    }
	return 0;
}
