#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

bool compare(std::pair<long, long> a , std::pair<long, long> b) {return a.first < b.first;}
    
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

    std::sort(ranges.begin(), ranges.end(), compare);

    std::vector<std::pair<long,long>> merged;

    for (std::vector<std::pair<long, long> >::iterator r = ranges.begin(); r != ranges.end(); ++r)
    {
        if (merged.empty() || merged.back().second < r->first)
            merged.push_back(*r);
        else
            merged.back().second = std::max(merged.back().second, r->second);
    }

    for (std::vector<std::pair<long, long> >::iterator it = merged.begin(); it != merged.end(); ++it)
    {
        if (it->second == 1 && it->first == 1)
            continue;
        sum += (it->second - it->first) +1;
    }
    std::cout << sum << std::endl;
    return 0;
}
