#pragma once

#include <algorithm>
#include <map>
#include <sstream>
#include <string>

typedef std::map<std::string, int> WordCounting;

WordCounting CountWord(std::string& str);