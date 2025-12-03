#include <fstream>
#include <iostream>
#include <sstream>

int main(int argc, char const *argv[])
{
    std::string line;
    std::ifstream input("/home/xortega/AoC2025/2/conbination.txt");
    long first_id;
    long end_id;
    long sum = 0;
    std::stringstream tmp;

    while (std::getline(input, line))
    {
        tmp.str(std::string());
        first_id = atoll(line.c_str());
        tmp << first_id;
        end_id = atoll(line.c_str() + tmp.tellp() + 1);
        for (size_t i = first_id; i <= end_id; i++)
        {
            tmp.str(std::string());
            tmp << i;
            bool valid = false;
            int tmp_size = tmp.tellp();
            for (size_t size = 1; size < tmp_size; size++)
            {
                std::string slice = tmp.str().substr(0,size);
                for (size_t k = 0; k < tmp_size; k += slice.length())
                {
                    if (k + slice.size() > tmp_size || slice != tmp.str().substr(k, k + slice.size())) break;
                    if (k + slice.size() == tmp_size)
                        sum += std::atoll(tmp.str().c_str());
                }
            }
        }
    }
    std::cout << sum << std::endl;
    return 0;
}
