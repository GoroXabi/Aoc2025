#include <fstream>
#include <iostream>

#define WIDTH 10
#define HEIGTH 10

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
    for (size_t i = 0; i < WIDTH; i++)
        std::cout << matrix[i] << std::endl;
    
    std::cout << "After :" << std::endl;

    for (size_t y = 0; y < WIDTH - 1; y++)
    {
        for (size_t x = 0; x < WIDTH - 1; x++)
        {
            int arround = 0;
            if (y != 0 && matrix[y- 1][x] == '@')
                arround++;
            if (y != 0 && x != 0 && matrix[y- 1][x - 1] == '@')
                arround++;
            if (y != 0 && x != WIDTH - 1 && matrix[y- 1][x + 1] == '@')
                arround++;
            std::cout << matrix[y][x];
        }
        std::cout << std::endl;

    }
    


    std::cout << sum << std::endl;
}
