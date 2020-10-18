#include "pch.h"
#include "../CountingWords/Process.h"
#include "../CountingWords/Process.cpp"


TEST(CountEmptyString)
{

	std::string str = "";
	WordCounting outMap = {};
	EXPECT_EQ(CountWord(str), outMap);
}


TEST(CountSpacesString)
{
	std::string str = "     ";
	WordCounting outMap = {};
	EXPECT_EQ(CountWord(str), outMap);
}


TEST(CountOneWord)
{
	std::string str = "HeLLo";
	WordCounting outMap = { {"hello", 1} };
	EXPECT_EQ(CountWord(str), outMap);
}


TEST(CountRepeatWords)
{
	std::string str = "HeLLo Hello heLLo";
	WordCounting outMap = { {"hello", 3} };
	EXPECT_EQ(CountWord(str), outMap);
}


TEST(CountLongString)
{
	std::string str = "Lorem ID ipsum dolor feUGiat loREM amet, id lorem FEugiat.";
	WordCounting outMap = { {"amet,", 1}, {"dolor", 1}, {"feugiat", 1}, {"feugiat.", 1}, {"id", 2}, {"ipsum", 1}, {"lorem", 3} };
	EXPECT_EQ(CountWord(str), outMap);
}
