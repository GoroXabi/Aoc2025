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
        long winner = std::atol(line.substr(line.length() - 12).c_str());
        std::cout << "max : "<< max << std::endl;

        for (std::vector<int>::iterator it = secuence.begin(); it < secuence.end() - 12; it++)
        {   
            std::vector<int> foe;
            std::string tmp = "";
            if (*it == max)
            {

                for (size_t i = 0; i < 12; i++)
                    foe.push_back(*(it + i));
                std::cout << "Before : ";
                for (size_t i = 0; i < 12; i++)
                    std::cout << foe[i];
                std::cout << std::endl;

                for (std::vector<int>::iterator it2 = it + 12; it2 < secuence.end(); it2++)
                {
                    int min = *std::min_element(foe.begin() + 1, foe.end());
                    std::cout << *it2 << " " << min << std::endl;
                    bool flag = true;
                    for (std::vector<int>::iterator it3 = foe.begin(); it3 != foe.end() - 1; ++it3) {
                        if (*it3 < *(it3 + 1))
                        {
                            std::cout << *it3 << std::endl;
                            foe.erase(it3);
                            foe.push_back(*it2);
                            flag = false;
                            break;
                        }
                    }
                    if (min < *it2 && flag)
                    {
                        foe.erase(std::find(foe.begin(), foe.end(), min));
                        foe.push_back(*it2);
                    }
                }
                
                for (std::vector<int>::iterator foe_it = foe.begin(); foe_it < foe.end(); foe_it++)
                    tmp.push_back(*foe_it + 48);

                std::vector<int>::iterator it2 = it + 1;
                std::cout << "After  : " << tmp << std::endl;

                if (winner < std::atol(tmp.c_str()))
                {
                    winner = std::atol(tmp.c_str());
                    std::cout << "Winner : " << winner << std::endl;
                }
            }
        }
        sum += winner;
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


3121910778619
 */
