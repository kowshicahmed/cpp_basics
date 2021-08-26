#include <iostream>
#include <vector>
#include <memory>

int main()
{
    //basic systax
    std::shared_ptr<int> p1 {   new int {100}  };
    std::cout << *p1 << std::endl;  //100
    *p1 = 200;
    std::cout << *p1 << std::endl;  //200
    
    //use_count = the number of shared_ptr objects managing the heap object
    std::shared_ptr <int> p2 {  new int {100}   };
    std::cout << p2.use_count () << std::endl;      //1
    
    std::shared_ptr<int> p3 {p2};       //shared ownership
    std::cout << p2.use_count () << std::endl;      //2
    
    p2.reset ();    //decrement the use_count, p2 is nulled out
    std::cout << p2.use_count () << std::endl;      //0
    std::cout << p3.use_count () << std::endl;      //1
    
    //using vector
    std::vector <std::shared_ptr <int>> vec;
    std::shared_ptr<int> ptr {new int {100}};
    vec.push_back (ptr); //OK-copy is allowed
    
    std::cout << ptr.use_count () << std::endl; //2
    
    //using make_shared
    std::shared_ptr<int> ptr1 = std::make_shared<int>(100);     //use_count : 1
    std::shared_ptr<int> ptr2 {ptr1};       //use_count : 2
    std::shared_ptr<int> ptr3;
    ptr3 = ptr1;                                        //use_count : 3
    
    
	return 0;
}
