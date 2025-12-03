#include <fstream>
#include <iostream>

int main(void) {
    std::string line;
    std::ifstream input("conbination.txt");
    int point = 50;
    int times_zero = 0;
    while (input.is_open() && std::getline(input, line)) {
        times_zero += (point + ((line[0] == 'R') - (line[0] == 'L')) * (atoi(line.c_str() + 1) % 100) == 0) + (point != 0) * (point + ((line[0] == 'R') - (line[0] == 'L')) * (atoi(line.c_str() + 1) % 100) < 0 || point + ((line[0] == 'R') - (line[0] == 'L')) * (atoi(line.c_str() + 1) % 100) > 99) + atoi(line.c_str() + 1) / 100;
        point = (point + ((line[0] == 'R') - (line[0] == 'L')) * (atoi(line.c_str() + 1) % 100) + 100) % 100;
    }
    return std::cout << "times 0: " << times_zero << std::endl, 0;
}
/* 
        int diff = ((line[0] == 'R') - (line[0] == 'L')) * (atoi(line.c_str() + 1) % 100);
        times_zero += (point + diff == 0) + (point != 0) * (point + diff < 0 || point + diff > 99) + atoi(line.c_str() + 1) / 100;
        point = (point + diff + 100) % 100; */