#include "common.h"

#include <sstream>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>

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

bool readLineIntoVector(std::istream& ifs, std::vector<int>& v)
{
    std::string line;

    if (!std::getline(ifs, line))
        return false;

    std::istringstream iss(line);
    int num;

    while (iss >> num)
       v.push_back(num);

    return true;
}

void printVector(const std::string& title, const std::vector<int>& v)
{
    std::cout << title << ": ";

    for (int e : v)
        std::cout << e << " | ";

    std::cout << "\n";
}

std::string printVectorToString(const std::vector<int>& v)
{
    std::ostringstream oss;

    for (int e : v)
        oss << e << " ";

    return oss.str();
}