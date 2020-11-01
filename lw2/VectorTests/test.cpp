#include "pch.h"

#include "../lw2/ProcessVector.cpp"

#include "../lw2/Vector.cpp"


TEST(ProcessVectorTests_Zero, Zero)
{
	std::vector<double> numbers{ 0.0 };
	ProcessVector(numbers);
	EXPECT_EQ(numbers, vecNumber{ 0.0 });
}

TEST(HtmlDecode_test_double_ampersand, asde)
{
	std::string strIn = "&&amp;";
	std::string strOut = "&&";
}


TEST(ProcessVectorTests_Not_Zero, Not_Zero)
{
	std::vector<double> numbers = { 18.0, 2.0, 15.0 };
	ProcessVector(numbers);
	std::vector<double> output = { 36.0, 4.0, 30.0 };
	EXPECT_EQ(numbers, output);
}

TEST(ProcessVectorTests_Minus, MinusValues)
{
	std::vector<double> numbers = { 18.0, -2.0, 15.0, 23.2,  19.0 };
	ProcessVector(numbers);
	std::vector<double> output = { -36.0, 4.0, -30.0, -46.4, -38.0 };
	EXPECT_EQ(numbers, output);
}

TEST(FillVector_Test, FillVector)
{
	std::vector<double> numbers = { 18.0, -2.0, 15.0, 23.2, 19.0 };
	FillVector(numbers);
	std::vector<double> output = { 18.0, -2.0, 15.0, 23.2, 19.0 };
	EXPECT_EQ(numbers, output);
}