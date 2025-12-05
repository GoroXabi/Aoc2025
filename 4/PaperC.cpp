#include <fstream>
#include <iostream>

//BLUE -> GREEN -> YELLOW -> RED
/*
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
 */

static const char* ANSI_32[65] = {
    "",    
    "\033[38;5;52m", "\033[38;5;52m",
    "\033[38;5;53m", "\033[38;5;53m",
    "\033[38;5;54m", "\033[38;5;54m",
    "\033[38;5;55m", "\033[38;5;55m", // VIOLET
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

};

static const char* ANSI_RESET = "\033[0m";

#define WIDTH 135
#define HEIGHT 135

const char*** heatmap = new const char**[HEIGHT];

int gen = 1;


bool compare(std::string *old_matrix, std::string *new_matrix)
{
    std::cout << "compare" << std::endl;
    for (size_t y = 0; y < HEIGHT; y++)
        for (size_t x = 0; x < WIDTH; x++)
            if (old_matrix[y][x] != new_matrix[y][x])
                return false;
    return true;
}

int countPaper(std::string *matrix)
{
    int paper = 0;
    for (size_t y = 0; y < HEIGHT; y++)
        for (size_t x = 0; x < WIDTH; x++)
            if (matrix[y][x] == '@')
                paper++;
    return(paper);
}

std::string *simulate(std::string *matrix){
    std::cout << "After :" << std::endl;
    std::string *new_matrix = new std::string[WIDTH];
    for (size_t y = 0; y < HEIGHT; y++)
        new_matrix[y] = matrix[y];

    for (size_t y = 0; y < HEIGHT; y++)
    {
        for (size_t x = 0; x < WIDTH; x++)
        {
            if (matrix[y][x] == '.')
            {
                std::cout << '.';
                new_matrix[y][x] = '.';
                continue;
            }
            if (matrix[y][x] == 'x')
            {
                std::cout << '.';
                new_matrix[y][x] = '.';
                continue;
            }
            int arround = 0;
            //TOP
            if (matrix[y - 1 + HEIGHT % HEIGHT][x + WIDTH % WIDTH] == '@')
                arround++;
            if (matrix[y - 1 + HEIGHT % HEIGHT][x - 1 + WIDTH % WIDTH] == '@')
                arround++;
            if (matrix[y - 1 + HEIGHT % HEIGHT][x + 1 + WIDTH % WIDTH] == '@')
                arround++;
            //BOTTOM
            if (matrix[y + 1 + HEIGHT % HEIGHT][x + WIDTH % WIDTH] == '@')
                arround++;
            if (matrix[y + 1 + HEIGHT % HEIGHT][x - 1 + WIDTH % WIDTH] == '@')
                arround++;
            if (matrix[y + 1 + HEIGHT % HEIGHT][x + 1 + WIDTH % WIDTH] == '@')
                arround++;
            //SIDES
            if (matrix[y + HEIGHT % HEIGHT][x - 1 + WIDTH % WIDTH] == '@')
                arround++;
            if (matrix[y + HEIGHT % HEIGHT][x + 1 + WIDTH % WIDTH] == '@')
                arround++;

            if (arround < 4)
            {
                heatmap[y + HEIGHT % HEIGHT][x + WIDTH % WIDTH] = ANSI_32[gen % 65 + 1];
                std::cout << heatmap[y + HEIGHT % HEIGHT][x] << 'x' << ANSI_RESET;
                new_matrix[y + HEIGHT % HEIGHT][x + WIDTH % WIDTH] = 'x';
            }
            else
            {
                std::cout << '@';
                new_matrix[y + HEIGHT % HEIGHT][x + WIDTH % WIDTH] = '@';
            }

        }
        std::cout << std::endl;
    }
    return (new_matrix);
}

int main(void) {

    std::string line;
    std::ifstream input("xabi.txt");
    std::string *matrix = new std::string[HEIGHT];
    std::string *new_matrix = new std::string[HEIGHT];
    int i = 0;
    while (input.is_open() && std::getline(input, line)) {
        matrix[i] = line;
        i++;
    }
    std::cout << "Before :" << std::endl;
    for (size_t i = 0; i < HEIGHT; i++)
        std::cout << matrix[i] << std::endl;
    
    int sum = countPaper(matrix);
    

    for (int y = 0; y < HEIGHT; ++y) {
        heatmap[y] = new const char*[WIDTH];
        for (size_t x = 0; x < WIDTH; x++)
            heatmap[y][x] = matrix[y][x] == '@' ? ANSI_32[60] : ANSI_32[1];
    }
    
    new_matrix = simulate(matrix);
    while (!compare(matrix, new_matrix))
    {
        gen++;
        delete[] matrix;
        matrix = new_matrix;
        new_matrix = simulate(matrix);
    }
    std::cout << sum - countPaper(new_matrix) << std::endl;
    std::cout << gen << std::endl;
    for (size_t y = 0; y < HEIGHT; y++)
    {
        for (size_t x = 0; x < WIDTH; x++)
           std::cout << heatmap[y][x] << "█" << ANSI_RESET;
        std::cout << std::endl;
    }
    for (size_t y = 0; y < HEIGHT; y++)
    {
        for (size_t x = 0; x < WIDTH; x++)
           std::cout << heatmap[y][x] << "@" << ANSI_RESET;
        std::cout << std::endl;
    }
    for (int i = 1; i < 65; ++i) {
        std::cout << ANSI_32[i] << "█";
    }

    std::cout << "\033[38;5;15m" << std::endl;

    for (size_t i = 0; i < HEIGHT; i++)
        std::cout << new_matrix[i] << std::endl;
    std::cout << "\033[0m\n" << std::endl;
    return(0);
}

//Editor: Line Height