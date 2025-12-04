#include <fstream>
#include <iostream>

#define WIDTH 135
#define HEIGTH 135

bool compare(std::string *old_matrix, std::string *new_matrix)
{
    std::cout << "compare" << std::endl;
    for (size_t y = 0; y < HEIGTH; y++)
        for (size_t x = 0; x < WIDTH; x++)
            if (old_matrix[y][x] != new_matrix[y][x])
                return false;
    return true;
}

int countPaper(std::string *matrix)
{
    int paper = 0;
    for (size_t y = 0; y < HEIGTH; y++)
        for (size_t x = 0; x < WIDTH; x++)
            if (matrix[y][x] == '@')
                paper++;
    return(paper);
}

std::string *simulate(std::string *matrix){
    std::cout << "After :" << std::endl;
    std::string *new_matrix = new std::string[WIDTH];
    for (size_t y = 0; y < HEIGTH; y++)
        new_matrix[y] = matrix[y];


    for (size_t y = 0; y < HEIGTH; y++)
    {
        for (size_t x = 0; x < WIDTH; x++)
        {
            if (matrix[y][x] == '.')
            {
                std::cout << '.';
                new_matrix[y][x] = '.';
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
                new_matrix[y][x] = 'x';
            }
            else
            {
                std::cout << '@';
                new_matrix[y][x] = '@';

            }

        }
        std::cout << std::endl;
    }
    return (new_matrix);
}

int main(void) {
    std::string line;
    std::ifstream input("conbination.txt");
    std::string *matrix = new std::string[WIDTH];
    std::string *new_matrix = new std::string[WIDTH];
    //std::string matrix[WIDTH];
    int i = 0;
    while (input.is_open() && std::getline(input, line)) {
        matrix[i] = line;
        i++;
    }
    std::cout << "Before :" << std::endl;
    for (size_t i = 0; i < HEIGTH; i++)
        std::cout << matrix[i] << std::endl;
    
    int sum = countPaper(matrix);
    
    new_matrix = simulate(matrix);
    while (!compare(matrix, new_matrix))
    {
        delete[] matrix;
        matrix = new_matrix;
        new_matrix = simulate(matrix);
    }
    std::cout << sum - countPaper(new_matrix) << std::endl;
}
