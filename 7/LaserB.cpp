#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>

int width;
int height;

int main(int argc, char const *argv[])
{
    std::string line;
    std::ifstream input("conbination.txt");
    std::vector<std::string > matrix;
    std::vector<std::vector<long> > long_matrix;

    while (std::getline(input, line))
        matrix.push_back(line);

    height = matrix.size();
    width = matrix[0].size();

    int seed = matrix[0].find('S');

    for (size_t y = 0; y < height; y++)
        long_matrix.push_back(std::vector<long>(width, 0));

    long_matrix[0][seed] = 1;
     
    for (size_t y = 0; y < height; y++)
    {
        for (size_t x = 0; x < width; x++)
        {
            if (y == 0)
                break;
            if (matrix[y][x] != '^')
                long_matrix[y][x] += long_matrix[y - 1][x];
        }
        for (size_t x = 0; x < width; x++)
        {
            if (matrix[y][x] == '^')
            {
                long_matrix[y][x-1] += long_matrix[y - 1][x];
                long_matrix[y][x+1] += long_matrix[y - 1][x];
            }
        }
    }

    std::cout << std::endl;

    for (size_t y = 0; y < height; y++)
    {
        for (size_t x = 0; x < width; x++)
           std::cout <<"["<< (long_matrix[y][x] > 9 ? "" : " ") << long_matrix[y][x] << "]";
        std::cout << std::endl;
    }

    long sum;
    sum = std::accumulate(long_matrix.back().begin(), long_matrix.back().end(), 0L);
    

        std::cout << sum << std::endl;
    return 0;
}

//56506120000 is too low
//2139765864
//2139765864
//10357305916520