#include "common.h"

#include <sstream>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

#define WIDTH (int)allElements[0].size()
#define HEIGHT (int)allElements.size()

bool Grid::loadFromFile(std::istream& is, bool force_check)
{
    std::string line;

    while (std::getline(is, line))
    {
        size_t currentLine = allElements.size();
        std::vector<gridElement_t> vecElements;

        int index = 0;
        for (char c : line)
            vecElements.push_back({ index++, currentLine, c});

        allElements.push_back(vecElements);
    }

    if (force_check)
    {
        size_t width = allElements[0].size();
        
        for (std::vector<gridElement_t> vecElements : allElements)
        {
            if (vecElements.size() != width)
                return false;
        }
    }

    return true;
}

void Grid::loadFromStream(std::istream& is)
{
    std::string line;

    while (std::getline(is, line))
    {
        std::istringstream iss(line);

        int index, line;
        char c;

        std::vector<gridElement_t> vecElements;

        while (iss >> index >> line >> c)
            vecElements.push_back({ index, line, c });

        allElements.push_back(vecElements);
    }
}

Grid Grid::rotate90()
{
    std::ostringstream oss;

    for (int i = 0; i < WIDTH; ++i)
    {
        for (int j = HEIGHT - 1; j >= 0; --j)
        {
            gridElement_t  e = allElements[j][i];
            oss << std::get<0>(e) << " " << std::get<1>(e) << " " << std::get<2>(e);
        }

        oss << "\n";
    }

    std::istringstream iss(oss.str());

    Grid newGrid;
    newGrid.loadFromStream(iss);
    return newGrid;
}

Grid Grid::losange()
{
    std::ostringstream oss;

    // Top left
    for (int j = 0; j < HEIGHT; ++j)
    {
        int k = j;

        for (int i = 0; k >= 0; ++i, --k)
        {
            gridElement_t  e = allElements[k][i];
            oss << std::get<0>(e) << " " << std::get<1>(e) << " " << std::get<2>(e);
        }

        oss << "\n";
    }

    // Mid-point
    for (int i = 1; i < WIDTH; ++i)
    {
        int k = i;

        for (int j = HEIGHT - 1; k < WIDTH; --j, ++k)
        {
            gridElement_t  e = allElements[j][k];
            oss << std::get<0>(e) << " " << std::get<1>(e) << " " << std::get<2>(e);
        }

        oss << "\n";
    }

    std::istringstream iss(oss.str());

    Grid newGrid;
    newGrid.loadFromStream(iss);
    return newGrid;
}

bool Grid::popRowAsString(std::string& outRow, std::vector<gridElement_t>& outVecElements)
{
    outRow.clear();

    if (!allElements.size())
        return false;

    std::vector<gridElement_t> vecElements = allElements[0];

    for (gridElement_t e : vecElements)
        outRow.push_back(std::get<2>(e));

    outVecElements = vecElements;

    allElements.erase(allElements.begin());

    return true;
}

// Solo functions
bool readTwoColumInputFromFile(std::istream& is, std::vector<int>& left, std::vector<int>& right)
{
    std::vector<int> result;

    std::string line;
    while (std::getline(is, line))
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

bool readLineIntoVector(std::istream& is, std::vector<int>& v)
{
    std::string line;

    if (!std::getline(is, line))
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
