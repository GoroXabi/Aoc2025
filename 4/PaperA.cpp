#include <fstream>
#include <iostream>

#define WIDTH 135
#define HEIGTH 135

int main(void) {
    std::string line;
    std::ifstream input("conbination.txt");
    int sum = 0;
    std::string matrix[WIDTH];
    int i = 0;
    while (input.is_open() && std::getline(input, line)) {
        matrix[i] = line;
        i++;
    }
    std::cout << "Before :" << std::endl;
    for (size_t i = 0; i < HEIGTH; i++)
        std::cout << matrix[i] << std::endl;

    std::cout << "After :" << std::endl;

    for (size_t y = 0; y < HEIGTH; y++)
    {
        for (size_t x = 0; x < WIDTH; x++)
        {
            if (matrix[y][x] == '.')
            {
                std::cout << '.';
                continue;
            }
            int arround = 0;
            //TOP
            if (y != 0 && matrix[y - 1][x] == '@')
                arround++;
            if (y != 0 && x != 0 && matrix[y - 1][x - 1] == '@')
                arround++;
            if (y != 0 && x != WIDTH && matrix[y - 1][x + 1] == '@')
                arround++;
            //BOTTOM
            if (y != HEIGTH - 1 && matrix[y + 1][x] == '@')
                arround++;
            if (y != HEIGTH - 1 && x != 0 && matrix[y + 1][x - 1] == '@')
                arround++;
            if (y != HEIGTH - 1 && x != WIDTH && matrix[y + 1][x + 1] == '@')
                arround++;
            //SIDES
            if (x != 0 && matrix[y][x - 1] == '@')
                arround++;
            if (x != WIDTH - 1 && matrix[y][x + 1] == '@')
                arround++;

            if (arround < 4)
            {
                std::cout << 'x';
                sum++;
            }
            else
                std::cout << '@';

        }
        std::cout << std::endl;

    }
    


    std::cout << sum << std::endl;
}
