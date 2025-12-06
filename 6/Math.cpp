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
    std::vector<std::vector<long> > nums;
    std::string operators;


    while (std::getline(input, line))
    {
        if(line[0] == '+' || line[0] == '*')
            break;
        std::stringstream tmp( line );

        long number;
        std::vector<long> newNums;
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
        long num = 0;
        if (operators[i] == '+')
            num = nums[0][i] + nums[1][i] + nums[2][i] + nums[3][i];
        if (operators[i] == '*')
            num = nums[0][i] * nums[1][i] * nums[2][i] * nums[3][i];
        sum += num;
    }
    
    
    std::cout << sum << std::endl;
    return 0;
}
