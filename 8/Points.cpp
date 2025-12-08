#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
#include <cmath>


class Point
{
    
public:
    Point(double x, double y, double z);
    ~Point();
    double x;
    double y;
    double z;
    bool operator==(const Point& other) const {
        return (x == other.x && y == other.y && z == other.z);}
};

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "Point(" << p.x << ", " << p.y << ", " << p.z << ")";
    return os;
}

Point::Point(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Point::~Point()
{
}

int main(int argc, char const *argv[])
{
    std::string line;
    std::ifstream input("conbination.txt");
    std::vector<Point > Points;

    while (std::getline(input, line))
    {
        std::stringstream ss(line);
        double x, y, z;
        char delimiter;

        ss >> x >> delimiter >> y >> delimiter >> z;
        std::cout << x << " " << y << " " << z << std::endl;

        Points.push_back(Point(x, y, z));
    }
    for (std::vector<Point >::iterator it = Points.begin(); it != Points.end(); it++)
        std::cout << *it << std::endl;
    //
    std::map<double, std::pair<Point, Point> > lengths;
    for (std::vector<Point >::iterator it = Points.begin(); it != Points.end(); it++)
    {
        for (std::vector<Point >::iterator it2 = it + 1; it2 != Points.end(); it2++)
        {
            double len = sqrt(pow(it->x - it2->x, 2) + pow(it->y - it2->y, 2) + pow(it->z - it2->z, 2));
            lengths.insert(std::make_pair(len, std::make_pair(*it, *it2)));
        }
    }
    //
    std::vector<std::vector<Point> > circuits;
    circuits.push_back({lengths.begin()->second.first, lengths.begin()->second.second});

    int max_conections = 1;
    for (std::map<double, std::pair<Point, Point> >::iterator it = lengths.begin(); it != lengths.end() && max_conections < 10; it++)
    {
        if (it == lengths.begin())
            continue;
        max_conections++;
        std::vector<std::vector<Point> >::iterator cit = circuits.begin();
        for (; cit != circuits.end(); cit++)
        {
            if(std::find(cit->begin(), cit->end(), it->second.first) != cit->end())
            {
                cit->push_back(it->second.second);
                break;
            }
            else if(std::find(cit->begin(), cit->end(), it->second.second) != cit->end())
            {
                cit->push_back(it->second.first);
                break;
            }
        }
        if (cit == circuits.end())
            circuits.push_back(std::vector<Point>{it->second.first, it->second.second});

        
    }

        
    for (std::vector<std::vector<Point> >::iterator cit = circuits.begin(); cit != circuits.end(); cit++)
    {
        for (int i = 0; i < cit->size(); i++)
        {

        // Compare each element with current one
        for (int j = i + 1; j < cit->size();) {
          
          	// Erase if duplicate is found->
            if (cit[j] == cit[i])
                cit->erase(cit->begin() + j);
            else
                j++;
        }
        }
    }

    std::cout << lengths.begin()->first << " " << lengths.begin()->second.first << " " << lengths.begin()->second.second << std::endl;
    for (std::vector<std::vector<Point> >::iterator cit = circuits.begin(); cit != circuits.end(); cit++)
    {
        std::cout << "circuit = ";
        for (std::vector<Point>::iterator pit = cit->begin(); pit != cit->end(); pit++)
            std::cout << *pit << " ";
        std::cout << std::endl;
    }

    
    

    return 0;
}