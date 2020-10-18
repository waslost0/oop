#pragma once


#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include "ProcessVector.h"

const int ROUNDING_FACTOR = 3;
const std::string ERROR_VALUE_NUMBER = "Invalid input";

bool FillVector(vecNumber& numbers);
void PrintVector(vecNumber& numbers);