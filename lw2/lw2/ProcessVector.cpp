#include "ProcessVector.h"


void ProcessVector(vecNumber& numbers)
{
	double minValue = *std::min_element(numbers.begin(), numbers.end());
	for (size_t i = 0; i < numbers.size(); ++i)
	{
		numbers[i] *= minValue;
	}
}