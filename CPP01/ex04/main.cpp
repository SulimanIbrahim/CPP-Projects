#include <iostream>
#include <fstream>
#include <string>
#include "Utils.hpp"



int main (int ac, char **av)
{
    int i = 0;
    if (ac == 4)
    {
        if (av[1])
        {
            std::string filename = av[1];
            std::ifstream file(filename);
            if (!file.is_open()){
                std::cerr << "\033[1;31mError while opening the file (" << filename + ")" << std::endl;
                return 1;
            }
            std::string line;
            std::string search = av[2];
            std::string replace = av[3];
            if (search.empty()){
                std::cout << "\033[1;31m empty string" << std::endl;
                return 1;
            }
            if (search == replace){
                std::cout << "\033[1;31mduplicated strings" << std::endl;
                return 1;
            }
                std::ofstream fileReplace (filename + ".replace");
                if (!fileReplace.is_open()){
                std::cerr << "\033[1;31mError while opening the file (" << filename + ".replace)" << std::endl;
                return 1;
            }
            while (!file.eof()){
                i = -1;
                std::getline(file, line);
                Utils::replace_line(line, search, replace);
                if (!file.eof())
                    fileReplace << line + "\n";
                else
                    fileReplace << line;
            }
            fileReplace.close();
            file.close();
        }
    } else{
         std::cerr << "\033[1;31mBad arguments " << std::endl;
                return 1;
    }
}