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
        std::cout << "id: " << first_id << " - " << end_id << std::endl;
        for (size_t i = first_id; i <= end_id; i++)
        {
            tmp.str(std::string());
            tmp << i;
            bool valid = true;
            int tmp_size = tmp.tellp();
            for (size_t size = 1; size <= tmp_size; size++)
            {
                std::string slice = tmp.str().substr(0,size);
                for (size_t k = 0; k <= tmp_size && valid; k += slice.length())
                {
                    if (slice.size() == tmp_size || slice != tmp.str().substr(k, slice.size())) break;
                    if (k + slice.size() == tmp_size)
                    {
                        //std::cout << "INVALID :" << tmp.str() << std::endl;
                        sum += std::atoll(tmp.str().c_str());
                        valid = false;
                    }
                }
            }
        }
    }
    std::cout << sum << std::endl;
    return 0;
}
