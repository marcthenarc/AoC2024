#pragma once

#include <vector>
#include <fstream>
#include <string>

bool readTwoColumInputFromFile(std::istream& ifs, std::vector<int>& left, std::vector<int>& right);
void printVector(const std::string& title, const std::vector<int>& v);

