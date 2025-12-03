#include <fstream>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::string line;
    std::ifstream input("conbination.txt");
    int point = 50;
    int times_zero = 0;
    while (std::getline(input, line))
    {
        int diff = atoi(line.c_str() + 1);

        times_zero += diff / 100;
        diff = diff % 100;

        int pre_point = point;
    
        point += ((line[0] == 'R') - (line[0] == 'L')) * diff;

        times_zero += (point == 0);

        if (point < 0 || point > 99){
            times_zero += (pre_point != 0);
            point = (point + 100) % 100;
        }
        if (point < 0 || point > 99){
            times_zero += (pre_point != 0) * (point < 0 || point > 99);
            point = (point + 100) % 100;
        }
    }
    std::cout << "times 0: " << times_zero << std::endl;
    return 0;
}
