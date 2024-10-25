#include <iostream>
#include <fstream>
#include <string>

void replace_line(std::string& line, std::string& search, std::string& replace)
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
                replace_line(line, search, replace);
                if (!file.eof())
                    fileReplace << line + "\n";
                else
                    fileReplace << line;
            }
            fileReplace.close();
        file.close();
        }
    }
}