#include <iostream>
#include <fstream>
#include <string>

void word_replace(std::string& line, std::string& search, std::string& replace)
{
    size_t pos = 0;
    while((pos = line.find(search, pos)) != std::string::npos)
    {
        line.erase(pos, search.length());
        line.insert(pos, replace);
        pos = replace.length();
    }
}

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
                std::cout << "\033[1;31mthe sting you looking for in not there bruh" << std::endl;
                return 1;
            }
            if (search == replace){
                std::cout << "\033[1;31mduplicated strings" << std::endl;
                return 1;
            }
            while (!file.eof()){
                i = -1;
                std::getline(file, line);
                word_replace(line, search, replace);
                std::ofstream fileReplace (filename + ".replace");
                if (!fileReplace.is_open()){
                std::cerr << "\033[1;31mError while opening the file (" << filename + ".replace)" << std::endl;
                return 1;
            }
                fileReplace << line ;
            }
        file.close();
        }
    }
}