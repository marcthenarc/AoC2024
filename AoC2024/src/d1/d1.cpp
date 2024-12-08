#pragma once

#include "d1.h"
#include "../common.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <fstream>

void d1p1(const std::string& filename)
{
	std::ifstream ifs(filename.c_str());

	std::vector<int> left, right;

	if (!readTwoColumInputFromFile(ifs, left, right))
	{
		std::cerr << "Error: left != right\n";
		std::exit(-1);
	}

	std::sort(left.begin(), left.end());
	std::sort(right.begin(), right.end());

	std::vector<int> distances;

	for (int i = 0; i < left.size(); ++i)
		distances.push_back(std::abs(left[i] - right[i]));

	std::cout << "D1-P1 Total: " << std::accumulate(distances.begin(), distances.end(), 0) << "\n";
}

void d1p2(const std::string& filename)
{
	std::ifstream ifs(filename.c_str());

	std::vector<int> left, right;

	if (!readTwoColumInputFromFile(ifs, left, right))
	{
		std::cerr << "Error: left != right\n";
		std::exit(-1);
	}

	int score = 0;

	for (int eLeft : left)
	{
		int times = 0;

		for (int eRight : right)
		{
			if (eLeft == eRight)
				++times;
		}

		score += eLeft * times;
	}

	std::cout << "D1-P2 Total: " << score << "\n";
}

