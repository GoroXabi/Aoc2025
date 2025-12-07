#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>

int main(int argc, char const *argv[])
{
    std::string line;
    std::ifstream input("conbination.txt");
    long sum = 0;
    std::vector<std::string > matrix;
    std::string operators;
    std::vector<long> buffer;

    while (std::getline(input, line) && !(line[0] == '+' || line[0] == '*'))
        matrix.push_back(line);

        operators = line;

    for (size_t i = operators.size(); i > 0; --i)
    {
        long tmp = 0;
        if (matrix[0][i - 1] != ' ') tmp = tmp * 10 + (matrix[0][i - 1] - 48);
        if (matrix[1][i - 1] != ' ') tmp = tmp * 10 + (matrix[1][i - 1] - 48);
        if (matrix[2][i - 1] != ' ') tmp = tmp * 10 + (matrix[2][i - 1] - 48);
        if (matrix[3][i - 1] != ' ') tmp = tmp * 10 + (matrix[3][i - 1] - 48);
        
        if (tmp != 0) buffer.push_back(tmp);

        if (operators[i - 1] == '+')
        {
            sum += std::accumulate(buffer.begin(), buffer.end(), long(0));
            buffer.clear();
        }
        if (operators[i - 1] == '*')
        {
            sum += std::accumulate(buffer.begin(), buffer.end(), 1L, std::multiplies<long>());
            buffer.clear();
        }
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