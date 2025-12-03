#include <fstream>
#include <iostream>

int main(void) {
    std::string line;
    std::ifstream input("conbination.txt");
    int sum = 0;
    while (input.is_open() && std::getline(input, line)) {
        char    biggest1 = '0';
        char    biggest2 = '0';
        int     arrow;
        for (size_t i = 0; i < line.length() - 1; i++)
        {
            if (biggest1 < line[i])
            {
                biggest1 = line[i];
                arrow = i;
            }
        }
        for (size_t i = arrow + 1; i < line.length(); i++)
            if (biggest2 < line[i])
                biggest2 = line[i];
        sum += (biggest1 - 48) * 10 + biggest2 - 48;
        std::cout << biggest1 << biggest2 << std::endl;
    }
    std::cout << sum << std::endl;
}

/*         std::string halfA = line.substr(0, line.length()/2);
        std::string halfB = line.substr(line.length()/2);
        std::cout << halfA << " " << halfB << std::endl;
        char biggestA = '0';
        char biggestB = '0';
        for (size_t i = 0; i < halfA.length(); i++)
        {
            if (biggestA < halfA[i])
                biggestA = halfA[i];
            if (biggestB < halfB[i])
                biggestB = halfB[i];
        }
         */