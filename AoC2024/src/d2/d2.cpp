#include "d2.h"
#include "../common.h"

#include <fstream>
#include <vector>
#include <iostream>

#include <fstream>
#include <vector>
#include <iostream>
#include <bitset>

const int UNSAFE = 0;
const int FIRST = 1;
const int INCREASING = 2;
const int DECREASING = 3;
const int MAX = 4;

static bool isSafe(const std::vector<int> data)
{
	std::bitset<MAX> bits;

	int previous = -1;

	for (int e : data)
	{
		// Flag to set that a first number was recorded
		if (!bits.test(FIRST))
		{
			bits.set(FIRST);
		}
		else
		{
			// Identical numbers or wide difference is a fail
			if (previous == e || std::abs(previous - e) > 3)
				bits.set(UNSAFE);
			// If direction is not set
			else if (!bits.test(INCREASING) && !bits.test(DECREASING))
				bits.set((previous < e) ? INCREASING : DECREASING);
			// Test directionality
			else if ((bits.test(INCREASING) && previous > e) || (bits.test(DECREASING) && previous < e))
				bits.set(UNSAFE);

			// Exit on fail
			if (bits.test(UNSAFE))
				break;
		}

		previous = e;
	}

	return (!bits.test(UNSAFE));
}

void d2p1(const std::string& filename)
{
	std::ifstream ifs(filename.c_str());

	std::vector<int> data;
	int numberSafe = 0;

	while (readLineIntoVector(ifs, data))
	{
		if (data.empty())
			break;

		if (isSafe(data))
			++numberSafe;

		data.clear();
	}

	std::cout << "D2-P1 Total: " << numberSafe << "\n";
}

void d2p2(const std::string& filename)
{
	std::ifstream ifs(filename.c_str());

	std::vector<int> data;
	int numberSafe = 0;

	while (readLineIntoVector(ifs, data))
	{
		if (data.empty())
			break;

		// comparing unsigned and signed --- force it!
		for (int i = -1; i < (int)data.size(); i++)
		{
			std::vector<int> copie = data;

			// Remove one level until we have a safe report
			if (i != -1)
				copie.erase(copie.begin() + i);

			if (isSafe(copie))
			{
				++numberSafe;
				break;
			}
		}

		data.clear();
	}

	std::cout << "D2-P2 Total: " << numberSafe << "\n";
}