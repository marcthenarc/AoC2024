#include "d3.h"
#include "../common.h"

#include <fstream>
#include <vector>
#include <iostream>
#include <regex>

static int calculate(std::string mul_expr)
{
    std::regex digits("\\d+");

    auto wb =
        std::sregex_iterator(mul_expr.begin(), mul_expr.end(), digits);
    auto we = std::sregex_iterator();

    int total = 1;

    for (std::sregex_iterator i = wb; i != we; ++i)
    {
        std::smatch match = *i;
        std::string match_str = match.str();
        total *= atoi(match_str.c_str());
    }

    return total;
}

void d3p1(const std::string& filename)
{
    std::ifstream ifs(filename.c_str());
    std::string str(std::istreambuf_iterator<char>{ifs}, {});

    std::regex mul_regex("mul\\(\\d+,\\d+\\)");

    auto wb =
        std::sregex_iterator(str.begin(), str.end(), mul_regex);
    auto we = std::sregex_iterator();

    int total = 0;

    for (std::sregex_iterator i = wb; i != we; ++i)
    {
        std::smatch match = *i;
        std::string match_str = match.str();
        total += calculate(match_str);
    }

    std::cout << "D3-P1 Total: " << total << "\n";
}

void d3p2(const std::string& filename)
{
    std::ifstream ifs(filename.c_str());
    std::string str(std::istreambuf_iterator<char>{ifs}, {});

    std::regex mul_regex("(mul\\(\\d+,\\d+\\)|don't\\(\\)|do\\(\\))");

    auto wb =
        std::sregex_iterator(str.begin(), str.end(), mul_regex);
    auto we = std::sregex_iterator();

    int total = 0;
    bool enable = true;

    for (std::sregex_iterator i = wb; i != we; ++i)
    {
        std::smatch match = *i;
        std::string match_str = match.str();

        if (match_str == "do()")
            enable = true;
        else if (match_str == "don't()")
            enable = false;
        else if (enable)
            total += calculate(match_str);
    }

    std::cout << "D3-P2 Total: " << total << "\n";
}