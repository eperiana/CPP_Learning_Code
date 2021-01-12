#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<unsigned int> count_lower(const std::string& string)
{
    std::vector<unsigned int> tab;
    for (char tmp = 'a'; tmp <= 'z'; tmp++)
    {
        tab.emplace_back(std::count(string.begin(),string.end(),tmp));
    }

    return tab;
}

void display_lower_occ(const std::vector<unsigned int>& tab)
{
    char car = 'a';

    for (auto val: tab)
    {
        std::cout << car << " : " << val << std::endl;
        car++;
    }
}



int main(int argc, char const *argv[])
{
    std::string string;
    std::string concat;
    
    std::cin >> string;

    while(string.compare("end") != 0)
    {
        concat += string;
        auto tab = count_lower(string);
        display_lower_occ(tab);
        std::cout << concat << std::endl;
        std::cin >> string;

    }
    
    
    return 0;
}
