#include <fstream>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::string line;
    std::ifstream input("conbination.txt");
    int point = 50;
    int pointL = 50;
    int times_zero = 0;
    while (std::getline(input, line))
    {
        int diff = atoi(line.c_str() + 1);
        if (line[0] == 'L')
            point += diff;
        if (line[0] == 'R')
            point += diff;
    }
    //std::cout << "R : " << pointL << std::endl;
    std::cout << "P : " << point << std::endl;
/*     std::cout << "R %: " << pointL%100 << std::endl;
    std::cout << "L %: " << pointR%100 << std::endl;
    std::cout << "L - R: " << (pointL - pointR) << std::endl;
    std::cout << "L - R %: " << (pointL - pointR) % 100 << std::endl;
    std::cout << "L + R: " << (pointL + pointR) << std::endl;
    std::cout << "L + R %: " << (pointL + pointR) % 100 << std::endl;
    std::cout << "L + R + L%100 + R%100: " << pointL + pointR - pointL %100 - pointR%100 << std::endl; */

    std::cout << "times 0: " << times_zero << std::endl;
    return 0;
}
