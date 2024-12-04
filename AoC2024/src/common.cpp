#include "common.h"

#include <sstream>
#include <string>
#include <algorithm>
#include <iostream>

bool readTwoColumInputFromFile(std::istream& ifs, std::vector<int>& left, std::vector<int>& right)
{
    std::vector<int> result;

    std::string line;
    while (std::getline(ifs, line))
    {
        std::istringstream iss(line);
        int a, b;

        if (iss >> a >> b)
        {
            left.push_back(a);
            right.push_back(b);
        }
    }

    return left.size() == right.size();
}

void printVector(const std::string& title, const std::vector<int>& v)
{
    std::cout << title << ": ";

    for (int e : v)
        std::cout << e << " | ";

    std::cout << "\n";
}
