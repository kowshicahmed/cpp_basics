#include "helper_funcs.h"

void print_header ()
{
    std::cout << std::setw (15) << std::left << "Student"
                    << std::setw (5) << "Score" << std::endl;
    std::cout << std::setw (20) << std::setfill ('-') << "" << std::endl;
    std::cout << std::setfill(' ');
}

void print_footer (double average)
{
    std::cout << std::setw(20) << std::setfill ('-') << "" << std::endl;
    std::cout << std::setfill (' ');
    std::cout << std::setw (15) << std::left << "Average Score"
                    << std::setw (5) << std::right << average;
}

void print_student (const std::string &student, int score)
{
    std::cout << std::setprecision (1) << std::fixed;
    std::cout << std::setw(15) << std::left << student
                    << std::setw (5) << std::right << score << std::endl;
}

// Return the number of correct responses
int process_response (const std::string &response, const std::string &answer_key)
{
    int score {0};
    for (size_t i = 0; i < answer_key.size(); ++i)
    {
        if (response.at(i) == answer_key.at(i))
            score++;
    }
    return score;
}

