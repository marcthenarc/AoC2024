#pragma once

#include <vector>
#include <fstream>
#include <string>

bool readTwoColumInputFromFile(std::istream& ifs, std::vector<int>& left, std::vector<int>& right);
bool readLineIntoVector(std::istream& ifs, std::vector<int>& v);
void printVector(const std::string& title, const std::vector<int>& v);
std::string printVectorToString(const std::vector<int>& v);
