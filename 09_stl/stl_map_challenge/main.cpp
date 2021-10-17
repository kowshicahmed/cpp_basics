#include <iostream>
#include <map>
#include <set>
#include <fstream>
#include <iomanip>

// Used for Part 1
// Display the word and count from the
// std::map<std::string, int>
void display_words(const std::map<std::string, int> &words)
{
    std::cout << std::setw(12) << std::left << "\nWord"
                    << std::setw(7) << std::right << "Count" << std::endl;
    std::cout << "==========================" << std::endl;
    for (auto pair: words)
        std::cout << std::setw(12) << std::left << pair.first
                        << std::setw(7) << std::right << pair.second << std::endl;
}

// Used for Part 2
// Display the word and occurences from the
// std::map<std::string, std::set<int>>
void display_words(const std::map<std::string, std::set<int>> &words)
{
    std::cout << std::setw(12) << std::left << "\nWord"
                    << "Occurences" << std::endl;
    std::cout << "====================================" << std::endl;
    for (auto pair: words)
    {
        std::cout << std::setw(12) << std::left << pair.first
                        << std::left << "[ ";
        for (auto i: pair.second)
            std::cout << i << " ";
        std::cout << "]" << std::endl;
    }
}

// This function removes periods, commas, semicolons and colon in 
// a string and returns the clean version
std::string clean_string(const std::string &s)
{
    std::string result;
    for (char c: s)
    {
        if (c == '.' || c == ',' || c == ':')
            continue;
        else
            result += c;
    }
    return result;
}

// Part 1 processes the file and builds a map of words and the
// number of times they occur in the file
void part1()
{
    std::map<std::string, int> words;
    std::string line;
    std::string word;
    std::ifstream in_file {"words.txt"};
    if (in_file)
    {
        while (std::getline (in_file, line))
        {
            std::stringstream iss (line);  // extract each word from the line
            while (iss >> word)                         
            {
                word = clean_string (word);         // clean the word from punctuations
                words[word]++;                           // this gets the value, so increment the value
               
               /* Another approach
                auto it = words.find(word);
                if (it == words.end())                  // insert the word to the map if the word is not found, with count = 1
                    words.insert(std::pair<std::string, int>(word, 1));
                else                                            // else the word is already there so increase the count
                    it->second++;
                     */
            }
        }
        
        in_file.close();
        display_words(words);
    }
    else
    {
        std::cerr << "Error opening input file" << std::endl;
    }
}

// Part 2 processes the file and builds a map of words and a 
// set of line numbers in which the word appears
void part2()
{
    std::map<std::string, std::set<int>> words;
    std::string line;
    std::string word;
    std::ifstream in_file {"words.txt"};
    int line_count{};
    if (in_file)
    {
        // You implement this code
        while (std::getline (in_file, line))
        {
            std::stringstream iss (line);  // extract each word from the line
            line_count++;
            while (iss >> word)                         
            {
                word = clean_string (word);         // clean the word from punctuations
                words [word].insert(line_count);
                
                /* Another approach
                auto it = words.find(word);
                if (it == words.end())                  // insert the word to the map if the word is not found with line_count
                    words.insert(std::pair<std::string, std::set<int>>(word, {line_count}));
                else                                            // else the word is already there so insert only the line_count
                    it->second.insert(line_count);
                     * */
            }
        }
        
        in_file.close();
        display_words(words);
    }
    else
    {
        std::cerr << "Error opening input file" << std::endl;
    }
}
int main(int argc, char **argv)
{
	part1();
    part2();
    
	return 0;
}
