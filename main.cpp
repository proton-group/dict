#include "freq.hpp"
#include <fstream>
int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        std::cout << "input error" << std::endl;
        return -1;
    }
    std::ifstream file(argv[1]);
    std::string buf;
    std::string word;
    int pos;
    FqDict dict;
    dict.useMap();
    while(std::getline(file, buf))
    {   
        while(buf != "")
        {
            pos = buf.find_first_of(" \n");
            word = buf.substr(0,pos);
            dict.add_word(word);
            buf = buf.substr(pos);
        }
    }
    FqDict dict;
    return 0;
}
