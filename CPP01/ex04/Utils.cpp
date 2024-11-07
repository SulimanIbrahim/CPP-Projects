#include "Utils.hpp"

void Utils::replace_line(std::string& line, std::string& search, std::string& replace)
{
    size_t pos = 0;
    while((pos = line.find(search, pos)) != std::string::npos)
    {
        line.erase(pos, search.length());
        line.insert(pos, replace);
        pos = replace.length();
    }
}
