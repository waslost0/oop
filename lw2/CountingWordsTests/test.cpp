#include "pch.h"
#include "../CountingWords/Process.cpp"


TEST(CountingWords, CountEmptyString)
{

	std::string str = "";
	WordCounting outMap = {};
	EXPECT_EQ(CountWord(str), outMap);
}


TEST(CountingWords, CountSpacesString)
{
	std::string str = "     ";
	WordCounting outMap = {};
	EXPECT_EQ(CountWord(str), outMap);
}


TEST(CountingWords, CountOneWord)
{
	std::string str = "HeLLo";
	WordCounting outMap = { {"hello", 1} };
	EXPECT_EQ(CountWord(str), outMap);
}


TEST(CountingWords, CountRepeatWords)
{
	std::string str = "HeLLo HelLo heLLo";
	WordCounting outMap = { {"hello", 3} };
	EXPECT_EQ(CountWord(str), outMap);
}


TEST(CountingWords, CountLongString)
{
	std::string str = "Lorem ID ipsum dolor feUGiat loREM amet, id lorem FEugiat.";
	WordCounting outMap = { {"amet,", 1}, {"dolor", 1}, {"feugiat", 1}, {"feugiat.", 1}, {"id", 2}, {"ipsum", 1}, {"lorem", 3} };
	EXPECT_EQ(CountWord(str), outMap);
}
