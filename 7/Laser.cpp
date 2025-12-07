#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>

long sum = 0;
int width;
int higth;

void ray(int y, int x, std::vector<std::string > &matrix)
{
    if (y == higth - 1)
    {
        sum++;
        std::cout << sum << std::endl;
        return;
    }
    if (x == width || x < 0)
        return;
    if (matrix[y][x] == '.' || matrix[y][x] == 'S')
        ray(y + 1, x, matrix);
    if (matrix[y][x] == '^')
    {
        ray(y + 1, x + 1, matrix);
        ray(y + 1, x - 1, matrix);
    }
    return;
}

int main(int argc, char const *argv[])
{
    std::string line;
    std::ifstream input("conbination.txt");
    std::vector<std::string > matrix;
    std::vector<long> buffer;

    while (std::getline(input, line))
        matrix.push_back(line);

    higth = matrix.size();
    width = matrix[0].size();

    int seed = matrix[0].find('S');

    ray(0, seed, matrix);

        std::cout << sum << std::endl;
    return 0;
}

//565061200 is too low