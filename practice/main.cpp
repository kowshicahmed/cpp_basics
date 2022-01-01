#include <iostream>
#include <string>
#include <sstream>

int32_t date_glob = 2012011;
int32_t time_glob = 21035;
int32_t time_format_glob = 48;

std::string int_to_str (int32_t data)
{
    std::stringstream ss;
    ss << data;
    std::string data_str;
    ss >> data_str;
    return data_str;
}

std::string getTimeStamp()
{
    int32_t time = time_glob;
    int32_t date = date_glob;
    int32_t time_format = time_format_glob;

    std::string time_str = int_to_str(time);
    std::string date_str = int_to_str(date);
    std::string time_offset;

    std::string date_formatted = date_str.substr(0,4) + "-" + date_str.substr(4,2) + "-" + date_str.substr(6,2);
    std::string time_formatted_temp = std::string(time_str.rbegin(), time_str.rend());
    std::string time_formatted = time_formatted_temp.substr(5,1) + time_formatted_temp.substr(4,1) 
                                + ":" + time_formatted_temp.substr(3,1) + time_formatted_temp.substr(2,1) 
                                + ":" + time_formatted_temp.substr(1,1) + time_formatted_temp.substr(0,1);
    
    if (time_format == 48)
    {
        time_offset = "+" + std::string("0100");
    }
    else if (time_format == 0 || time_format == 24)
    {
        time_offset = "+" + std::string("0000");
    }
    else
    {
        time_format = time_format - 24;
        std::stringstream ss3;
        ss3 << time_format;
        ss3 >> time_offset;
        if (time_format < 0 && time_format > -10)
            time_offset = "-" + std::string{"0"} + time_offset.at(1) + std::string{"00"};
        else if (time_format <= -10)
            time_offset = time_offset + "00";
        else if (time_format >= 0 && time_format < 10)
            time_offset = "+" + std::string{"0"} + time_offset;
        else
            time_offset = "+" + time_offset + "00";
    }
    return date_formatted + "T" + time_formatted + time_offset;
}

int main()
{
    
    //std::cout << int_to_str (date_glob) << std::endl;
    std::cout << getTimeStamp() << std::endl;

    return 0;

}