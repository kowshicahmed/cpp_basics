#ifndef HELPER_FUNCS_H
#define HELPER_FUNCS_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

void print_header ();
void print_footer (double average);
void print_student (const std::string &student, int score);
int process_response (const std::string &response, const std::string &answer_key);

#endif // HELPER_FUNCS_H
