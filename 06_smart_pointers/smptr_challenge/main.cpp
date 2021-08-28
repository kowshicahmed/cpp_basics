#include <iostream>
#include <memory>
#include <vector>

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


//Functions prototypes
//std::unique_ptr<std::vector<std::shared_ptr <Test>>> make ();
auto make (); // the previos function's return type can be replace with auto since compiler knows what we are returning
void fill (std::vector<std::shared_ptr<Test>> &vec, int num);
void display (const std::vector<std::shared_ptr <Test>> &vec);

//the definition of auto function should be before main
auto make ()
{
    return std::make_unique <std::vector<std::shared_ptr <Test>>> ();
}

int main(int argc, char **argv)
{
	std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
    vec_ptr = make ();
    std::cout << "How many data points do you want to enter: ";
    int num;
    std::cin >> num;
    fill (*vec_ptr, num);
    display(*vec_ptr);
    
	return 0;
}



void fill (std::vector<std::shared_ptr<Test>> &vec, int num)
{
    int user_data {};
    for (int i {1}; i <= num; i++)
    {
        std::cout << " Enter data point " << "[" << i << "] : ";
        std::cin >> user_data;
        //std::shared_ptr<Test> ptr = std::make_shared <Test> (user_data);
        //vec.push_back (ptr);
        
        vec.push_back (std::make_shared <Test> (user_data)); //using one line
    }
}

void display (const std::vector<std::shared_ptr <Test>> &vec)
{
   std::cout << "\nDisplaying vector data" << std::endl;
   std::cout << "=================" << std::endl;

    for (const auto &ptr: vec)
        {
            std::cout << "\t" << ptr->get_data () << std:: endl;
        }
        
    std::cout << "=================" << std::endl;
}
