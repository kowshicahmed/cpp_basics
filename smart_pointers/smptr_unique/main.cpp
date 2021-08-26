#include <iostream>
#include <memory>

int main(int argc, char **argv)
{
	//using unique pointer with new
    std::unique_ptr<int> p1 {new int {100}};
    std::cout << *p1 << std::endl;          //100
   
    *p1 = 200;
    std::cout << *p1 << std::endl;          //200
    std::cout << p1.get() << std::endl;  //address contained in p1
    
    p1.reset(); //p1 is now nullptr
    
    if (p1)
        std::cout << *p1 << std::endl;      //wont execute since p1 is null
    
    //using unique pointer without new
    std::unique_ptr<int> p2 = std::make_unique<int>(300);
    auto p3 = std::make_unique<int> (400);
    std::cout << *p2 << std::endl;          //300
    std::cout << *p3 << std::endl;          //400
    
    //unique pointer can not be copied but can be moved
    std::unique_ptr<int> p4;
    //p4 = p2; //error
    p4 = std::move(p2); // OK
    
	return 0;
}
