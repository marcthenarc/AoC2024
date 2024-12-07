#include "d4.h"
#include "../common.h"

#include <fstream>
#include <iostream>
#include <regex>
#include <algorithm>

std::vector<gridElement_t> found_once;

static int countX_MAS(Grid grid)
{
    int total = 0;
    std::string row;
    std::vector<gridElement_t> vec;

    while (grid.popRowAsString(row, vec))
    {
        std::regex xmas("MAS");

        auto wb =
            std::sregex_iterator(row.begin(), row.end(), xmas);
        auto we = std::sregex_iterator();

        // For each found matches
        for (std::sregex_iterator i = wb; i != we; ++i)
        {
            // Keep the crossing 'A' element
            gridElement_t elem = vec.at(i->position() + 1);

            // Check if we already have it from a previous hit
            bool isalreadyFound = false;

            for (const gridElement_t& found : found_once)
            {
                if (found == elem)
                {
                    total++;
                    isalreadyFound = true;
                }
            }

            // If not, add it.
            if (!isalreadyFound)
                found_once.push_back(elem);
        }
    }

    return total;
}

static int countXMAS(Grid grid)
{
    int total = 0;
    std::string row;
    std::vector<gridElement_t> unused;
    
    while (grid.popRowAsString(row, unused))
    {
        std::regex xmas("XMAS");

        auto wb =
            std::sregex_iterator(row.begin(), row.end(), xmas);
        auto we = std::sregex_iterator();

        total += (int)std::distance(wb, we);
    }

    return total;
}

void d4p1(const std::string& filename)
{
    std::ifstream ifs(filename.c_str());

    Grid grid;
    grid.loadFromFile(ifs, true);

    int total = 0;

    for (int i = 0; i < 4; i++)
    {
        total += countXMAS(grid);
        total += countXMAS(grid.losange());
        grid = grid.rotate90();
    }

    std::cout << "D4-P1 Total: " << total << "\n";
}

void d4p2(const std::string& filename)
{
    std::ifstream ifs(filename.c_str());

    Grid grid;
    grid.loadFromFile(ifs, true);

    int total = 0;

    for (int i = 0; i < 4; i++)
    {
        total += countX_MAS(grid.losange());
        grid = grid.rotate90();
    }

    std::cout << "D4-P2 Total: " << total << "\n";
}