#include "freq.hpp"
namespace
{
    std::stringstream print(std::vector<std::string>::iterator itervBegin,
                            std::vector<std::string>::iterator itervEnd,
                            std::vector<int>::iterator iterc)
    {
        std::stringstream out;
        for (itervBegin; itervBegin != itervEnd; ++itervBegin)
        {
            out << *itervBegin << " " << *iterc++ << "\n";
        }
        return out;
    }

    std::stringstream print(std::list<std::string>::iterator itervBegin,
                            std::list<std::string>::iterator itervEnd,
                            std::list<int>::iterator iterc)
    {
        std::stringstream out;
        for (itervBegin; itervBegin != itervEnd; ++itervBegin)
        {
            out << *itervBegin << " " << *iterc++ << "\n";
        }
        return out;
    }

    std::string word_for_cmp{""};
    bool isNew{true};

    int cmp(std::string first, int second)
        {
            if(first.compare(word_for_cmp) == 0)
            {
                isNew = false;
                return second + 1;
            }
            else
            {
                return second;
            }
        }

    void vectorAlg_insert(std::vector<std::string>& mem_vec, std::vector<int>& mem_count, std::string word)
    {
        word_for_cmp = word;
        //TODO: add pait
        std::transform(mem_vec.begin(), mem_vec.end(), mem_count.begin(), mem_count.begin(), cmp);
        if(isNew)
        {
            mem_vec.push_back(word);
            mem_count.push_back(1);
        }
        isNew = true;
    }

    void listAlg_insert(std::list<std::string>& mem_lis, std::list<int>& mem_lis_count, std::string word)
    {
        word_for_cmp = word;
        std::transform(mem_lis.begin(), mem_lis.end(), mem_lis_count.begin(), mem_lis_count.begin(), cmp);
        if(isNew)
        {
            mem_lis.push_back(word);
            mem_lis_count.push_back(1);
        }
        isNew = true;
    }

    void mapAlg_insert(std::unordered_map<std::string, int>& mem_map, std::string word)
    {
        std::unordered_map<std::string, int>::iterator iter;
        if((iter = mem_map.find(word)) != mem_map.end())
        {
            mem_map.insert_or_assign((*iter).first, (*iter).second+1);
        }
        else
        {
            mem_map.insert({word, 1});
        }
    }

    std::stringstream print(std::unordered_map<std::string, int>::iterator iterBegin,
                            std::unordered_map<std::string, int>::iterator iterEnd,
                            std::unordered_map<std::string, int> map
                            )
    {
        std::stringstream out;
        for (iterBegin; iterBegin != iterEnd; ++iterBegin)
        {
            out << (*iterBegin).first << " " << (*iterBegin).second << "\n";
        }
        return out;
    }
}

void FqDict::useVector()
{
    algType = 'v';
}

void FqDict::useMap()
{
    algType = 'm';
}

void FqDict::useList()
{
    algType = 'l';
}

void FqDict::add_word(std::string word)
{
    switch(algType)
    {
        case 'v':
            vectorAlg_insert(mem_vec, mem_count, word);
            break;
        case 'm':
            mapAlg_insert(mem_map, word);
            break;
        case 'l':
            listAlg_insert(mem_lis, mem_lis_count, word);
            break;
    }
}

std::stringstream FqDict::word_freq()
{
    switch(algType) //TODO: enum
    {
        case 'v':
            return print(mem_vec.begin(), mem_vec.end(), mem_count.begin());
        case 'm':
            return print(mem_map.begin(), mem_map.end(), mem_map);
        case 'l':
            return print(mem_lis.begin(), mem_lis.end(), mem_lis_count.begin());
    }
}