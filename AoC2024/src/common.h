#pragma once

#include <istream>
#include <string>
#include <vector>
#include <map>
#include <tuple>

typedef std::tuple<size_t, size_t, char> gridElement_t;
typedef std::vector<std::vector<int>> vectorInVectorInt_t;
typedef std::map<int, std::map<int, bool>> fastMapIntByInt_t;

class Grid
{
public:

	bool loadFromFile(std::istream& is, bool force_check = true);
	Grid rotate90();
	Grid losange();
	bool popRowAsString(std::string& outRow, std::vector<gridElement_t>& outVecElements);

private:

	std::vector <std::vector<gridElement_t>> allElements;
	void loadFromStream(std::istream& is);
};


bool readTwoColumInputFromFile(std::istream& is, std::vector<int>& left, std::vector<int>& right);
bool readLineIntoVector(std::istream& is, std::vector<int>& v);
void printVector(const std::string& title, const std::vector<int>& v);
std::string printVectorToString(const std::vector<int>& v);
vectorInVectorInt_t readNumbersWithSeparators(std::istream& is, const char& separator, bool quit_after_line_break = false);
