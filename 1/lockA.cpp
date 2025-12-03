#include <sstream>
#include <string>
#include <fstream>
#include <iostream>

int main(int argc, char const *argv[])
{
    
    std::string line;
    std::ifstream input("conbination.txt");
    if(!input.is_open())
		throw std::runtime_error("input not found");
    int point = 50;
    int times_zero = 0;
    while (std::getline(input, line))
    {
        int diff = atoi(line.c_str() + 1);
        
        diff = diff % 100;

        if (line[0] == 'L')
            point -= diff;
        if (line[0] == 'R')
            point += diff;

        if (point < 0)
            point = 100 + point;
        if (point > 99)
            point = point - 100;

        if (point == 0)
            times_zero++;
    }
    std::cout << times_zero << std::endl;
    return 0;
}
