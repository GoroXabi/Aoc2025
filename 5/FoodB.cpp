#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

int main(int argc, char const *argv[])
{
    std::string line;
    std::ifstream input("conbination.txt");
    long sum = 0;
    std::stringstream tmp;
    std::vector<std::pair<long, long> > ranges;

    while (std::getline(input, line))
    {
            long first = std::atol(line.c_str()); 
            long last = std::atol(line.substr((line.find('-'))).c_str() + 1);
            ranges.push_back(std::make_pair(first, last));
    }
    for (std::vector<std::pair<long, long> >::iterator it = ranges.begin(); it != ranges.end(); ++it)
    {
        for (std::vector<std::pair<long, long> >::iterator it2 = it + 1; it2 != ranges.end(); ++it2)
        {
            if (it->first >)
        }
    }
    for (std::vector<std::pair<long, long> >::iterator it = ranges.begin(); it != ranges.end(); ++it)
    {
        std::cout << it->second << " - " << it->first << " = " << (it->second - it->first) +1 << std::endl;
        sum += (it->second - it->first) +1;
    }
    std::cout << sum << std::endl;
    return 0;
}
