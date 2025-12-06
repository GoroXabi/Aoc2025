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
        if (line.find('-') == line.npos)
        {
            long id = std::atol(line.c_str()); 
            for (std::vector<std::pair<long, long> >::iterator it = ranges.begin(); it != ranges.end(); ++it)
            {
                if (it->first <= id && id <= it->second) {
                    sum++;
                    std::cout << id << std::endl;
                    break;
                }
            }
        }
        else
        {
            long first = std::atol(line.c_str()); 
            long last = std::atol(line.substr((line.find('-'))).c_str() + 1);
            ranges.push_back(std::make_pair(first, last));
            
        }
    }
    std::cout << sum << std::endl;
    return 0;
}
