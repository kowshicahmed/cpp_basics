#include "helper_funcs.h"

int main()
{
	std::ifstream in_file;
    std::string answer_key {};
    std::string name {};
    std::string response {};
    int running_sum {0};
    int total_students {0};
    double average_score {0.0};
    
    in_file.open ("responses.txt");
    if (!in_file)
    {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }
    
    in_file >> answer_key;
    
    print_header ();
    
    while (in_file >> name >> response)
    {
        ++total_students;
        int score = process_response (response, answer_key);
        running_sum += score;
        print_student (name, score);
    }
    
    if (total_students != 0)
    {
        average_score = static_cast <double> (running_sum) / total_students;
    }
    
    print_footer (average_score);
    
    std::cout << std::endl;
    in_file.close ();
    
	return 0;
}
