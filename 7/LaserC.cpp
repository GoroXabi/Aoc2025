#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>


//BLUE -> GREEN -> YELLOW -> RED

static const char* ANSI_32[65] = {
    "",
    "\033[38;5;17m", "\033[38;5;17m", //DARK BLUE
    "\033[38;5;18m", "\033[38;5;18m",
    "\033[38;5;19m", "\033[38;5;19m",
    "\033[38;5;20m", "\033[38;5;20m",
    "\033[38;5;21m", "\033[38;5;21m",
    "\033[38;5;27m", "\033[38;5;27m", //MEDIUM BLUE
    "\033[38;5;33m", "\033[38;5;33m",
    "\033[38;5;39m", "\033[38;5;39m",
    "\033[38;5;45m", "\033[38;5;45m",
    "\033[38;5;51m", "\033[38;5;51m", //LIGTH BLUE
    "\033[38;5;50m", "\033[38;5;50m",
    "\033[38;5;49m", "\033[38;5;49m",
    "\033[38;5;48m", "\033[38;5;48m",
    "\033[38;5;47m", "\033[38;5;47m", //GREEN
    "\033[38;5;46m", "\033[38;5;46m",
    "\033[38;5;82m", "\033[38;5;82m",
    "\033[38;5;118m", "\033[38;5;118m",
    "\033[38;5;154m", "\033[38;5;154m",
    "\033[38;5;190m", "\033[38;5;190m",
    "\033[38;5;226m", "\033[38;5;226m",
    "\033[38;5;220m", "\033[38;5;220m", //YELLOW
    "\033[38;5;214m", "\033[38;5;214m",
    "\033[38;5;208m", "\033[38;5;208m",
    "\033[38;5;202m", "\033[38;5;202m",
    "\033[38;5;196m", "\033[38;5;196m", //RED
    "\033[38;5;160m", "\033[38;5;160m",
    "\033[38;5;124m", "\033[38;5;124m",
    "\033[38;5;88m", "\033[38;5;88m",
    "\033[38;5;52m", "\033[38;5;52m",
    "\033[38;5;53m", "\033[38;5;53m",
    "\033[38;5;54m", "\033[38;5;54m",
    "\033[38;5;55m", "\033[38;5;55m", // VIOLET
};



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
           std::cout << ANSI_32[long_matrix[y][x] % 64] << "█";
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