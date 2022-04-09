#ifndef _FREQ_HPP
#define _FREQ_HPP
#include <sstream>
#include <vector>
#include <unordered_map>
#include <list>
#include <algorithm>
#include <iostream>

class FqDict
{
public:
    void add_word(std::string word);
    std::stringstream word_freq();
    void useVector();
    void useMap();
    void useList();
private:
    std::vector<std::string> mem_vec;
    std::vector<int> mem_count;
    std::unordered_map<std::string, int> mem_map;
    std::list<std::string> mem_lis;
    std::list<int> mem_lis_count;
    char algType;
};

#endif