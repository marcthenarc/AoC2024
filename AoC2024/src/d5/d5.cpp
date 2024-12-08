#include "d5.h"
#include "../common.h"

#include <iostream>
#include <algorithm>
#include <fstream>

fastMapIntByInt_t mapPageOrdering;
std::vector<std::tuple<std::vector<int>, std::vector<int>>> badOnes;

static bool findRule(int before, int after)
{
	// Correct match
	{
		auto it1 = mapPageOrdering.find(before);

		if (it1 != mapPageOrdering.end())
		{
			auto it2 = it1->second.find(after);

			if (it2 != it1->second.end())
				return true;
		}
	}

	// Contrairian match
	{
		auto it1 = mapPageOrdering.find(after);

		if (it1 != mapPageOrdering.end())
		{
			auto it2 = it1->second.find(before);

			if (it2 != it1->second.end())
				return false;
		}
	}

	return true;
}

static bool test(std::vector<int> update)
{
	bool good = true;

	for (size_t i = 0; i < update.size(); ++i)
	{
		for (size_t j = 0; j < update.size(); ++j)
		{
			std::vector<int> orderFaultonFalse;

			if (i < j)
				good &= findRule(update[i], update[j]);
			else if (i > j)
				good &= findRule(update[j], update[i]);

			// Short it!
			if (!good)
			{
				badOnes.push_back({ update, { update[i], update[j] } });
				return false;
			}
		}
	}

	return good;
}

static bool fixBadOne(std::tuple<std::vector<int>, std::vector<int>> badOne, std::vector<int>& outNewUpdate)
{
	auto update = std::get<0>(badOne);
	auto violationRule = std::get<1>(badOne);

	auto first = std::find(update.begin(), update.end(), violationRule[0]);
	auto second = std::find(update.begin(), update.end(), violationRule[1]);

	int swap = *first;
	*first = *second;
	*second = swap;

	if (test(update))
	{
		outNewUpdate = update;
		return true;
	}

	return false;
}

void d5p1(const std::string& filename)
{
	std::ifstream ifs(filename.c_str());

	if (!ifs)
		return;

	fastMapIntByInt_t::iterator foundIt;

	vectorInVectorInt_t pageOrdering = readNumbersWithSeparators(ifs, '|', true /* quit after empty line*/);

	for (auto rule : pageOrdering)
	{
		foundIt = mapPageOrdering.find(rule[0]);

		if (foundIt == mapPageOrdering.end())
			mapPageOrdering[rule[0]].insert({ rule[1], true });
		else
			(*foundIt).second[rule[1]] = true;
	}

	std::vector<std::vector<int>> pagesToUpdate = readNumbersWithSeparators(ifs, ',');
	std::vector<std::vector<int>> goodOnes;

	for (std::vector<int> update : pagesToUpdate)
	{
		if (test(update))
			goodOnes.push_back(update);
	}

	int total = 0;

	for (auto goodOne : goodOnes)
	{
		size_t middle = goodOne.size() / 2;
		total += goodOne[middle];
	}

	std::cout << "D5-P1 Total: " << total << "\n";
}

// Note: d5p1 must be done first to keep the badOnes
void d5p2(const std::string& filename)
{
	std::vector<std::vector<int>> goodOnes;

	while (badOnes.size())
	{
		std::tuple<std::vector<int>, std::vector<int>> badOne = badOnes[0];
		std::vector<int> updated;

		if (fixBadOne(badOne, updated))
			goodOnes.push_back(updated);

		badOnes.erase(badOnes.begin());
	}

	int total = 0;

	for (auto goodOne : goodOnes)
	{
		size_t middle = goodOne.size() / 2;
		total += goodOne[middle];
	}

	std::cout << "D5-P2 Total: " << total << "\n";
}