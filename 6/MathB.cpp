#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

long sumAll(std::string first, std::string second, std::string third, std::string fourth)
{
    long sum = 0;
    while (!first.empty() || !second.empty() || !third.empty() || !fourth.empty())
    {
        std::string tmp;
        if (!first.empty())
        {
            tmp.push_back(first.front());
            first.erase(0, 1);
        }
        if (!second.empty())
        {
            tmp.push_back(second.front());
            second.erase(0, 1);
        }
        if (!third.empty())
        {
            tmp.push_back(third.front());
            third.erase(0, 1);
        }
        if (!fourth.empty())
        {
            tmp.push_back(fourth.front());
            fourth.erase(0, 1);
        }
        sum += std::atol(tmp.c_str());
    }
    return sum;
}


long multAll(std::string first, std::string second, std::string third, std::string fourth)
{
    long sum = 1;
    int longest = std::max(first.size(), second.size(), third.size(), fourth.size())
    while (!first.empty() || !second.empty() || !third.empty() || !fourth.empty())
    {
        std::string tmp;
        if (!first.empty())
        {
            tmp.push_back(first.front());
            first.erase(0, 1);
        }
        if (!second.empty())
        {
            tmp.push_back(second.front());
            second.erase(0, 1);
        }
        if (!third.empty())
        {
            tmp.push_back(third.front());
            third.erase(0, 1);
        }
        if (!fourth.empty())
        {
            tmp.push_back(fourth.front());
            fourth.erase(0, 1);
        }
        std::cout << tmp << " * ";
        sum *= std::atol(tmp.c_str());
    }
    std::cout << " = " << sum << std::endl;

    return sum;
}



int main(int argc, char const *argv[])
{
    std::string line;
    std::ifstream input("conbination.txt");
    long sum = 0;
    std::stringstream tmp;
    std::vector<std::vector<std::string> > nums;
    std::string operators;

    while (std::getline(input, line))
    {
        if(line[0] == '+' || line[0] == '*')
            break;
        std::stringstream tmp( line );

        std::string number;
        std::vector<std::string> newNums;
        while ( tmp >> number )
            newNums.push_back( number );
        nums.push_back(newNums);
        
    }
    operators = line;
    operators.erase(std::remove(operators.begin(), operators.end(), ' '), operators.end());

/*     for (std::vector<long> &vec : nums)
    {
        for (long i : vec)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    for (char c : operators)
    {
        std::cout << c << " ";
    }
    std::cout << std::endl; */
    
    for (size_t i = 0; i < operators.size(); i++)
    {
        if (operators[i] == '+')
            sum += sumAll(nums[0][i], nums[1][i], nums[2][i], std::string(""));
        if (operators[i] == '*')
            sum += multAll(nums[0][i], nums[1][i], nums[2][i], std::string(""));
    }
    
    std::cout << sum << std::endl;
    return 0;
}


/*     for (size_t i = 0; i < operators.size(); i++)
    {
        long num = 0;
        if (operators[i] == '+')
            num = std::atol(nums[0][i].c_str())
            + std::atol(nums[1][i].c_str())
            + std::atol(nums[2][i].c_str())
            + std::atol(nums[3][i].c_str());
        if (operators[i] == '*')
            num = std::atol(nums[0][i].c_str())
            * std::atol(nums[1][i].c_str())
            * std::atol(nums[2][i].c_str())
            * std::atol(nums[3][i].c_str());
        sum += num;
    }
*/