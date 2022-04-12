#ifndef __SUBSTRING_H__
#define __SUBSTRING_H__

#include <vector>
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <algorithm>

class substring
{
public:
	substring();
	std::vector<int> Rabin_Karp(std::vector<int> T, std::vector<int> P);
	std::vector<int> prefix_func(std::vector<char> S);
	std::vector<int> knuth_morris_pratt(std::vector<char> T, std::vector<char> P);
	std::vector<int> getSuffixTable(std::vector<char> P);
	std::vector<int> getStopTable(std::vector<char> P);
	std::vector<int> boyer_moor(std::vector<char> T, std::vector<char> P);
};

#include "substring.cpp"
#endif
