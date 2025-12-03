#include <fstream>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int main(void) {
    std::string line;
    std::ifstream input("conbination.txt");
    long sum = 0;
    while (input.is_open() && std::getline(input, line)) {
        std::vector<int> secuence;
        for (size_t i = 0; i < line.length(); i++)
            secuence.push_back(line[i] - 48);
        int max = *std::max_element(secuence.begin(), secuence.end() - 12);
        long winner = 0;
        long foe = 0;
        std::cout << "max : "<< max << std::endl;
        for (std::vector<int>::iterator it = secuence.begin(); it < secuence.end() - 12; it++)
        {
            std::string tmp = "";
            if (*it == max)
            {
            
                for (size_t i = 0; i < 12; i++)
                    tmp.push_back(*(it + i) + 48);
                it += 12;
                winner = std::atol(tmp.c_str());
                ////////////////////
                std::vector<int>::iterator it2 = it + 1;

            }
            if (winner < std::atol(tmp.c_str()))
                
        }
        sum += winner;
        std::cout << winner << std::endl;
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

/* 
987654321111
811111111119
434234234278
888911112111
 */
