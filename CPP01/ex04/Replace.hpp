#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <string>
#include <fstream>
#include <iostream>


class Replace 
{
    public:
        void replace_line(std::string& line, std::string& search, std::string& replace);

};

#endif