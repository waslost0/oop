#include "pch.h"
#include "../GeneratePrimeNumbersSet/Primes.cpp"

TEST(InitVectorOfPrimes, InputValue_2)
{
    std::vector<bool> outVec = { false, false, true };
    EXPECT_EQ(InitVectorOfPrimes(2), outVec);
}

TEST(InitVectorOfPrimes, InputValue_6)
{
    std::vector<bool> outVec = { false, false, true, true, false, true, false };
    EXPECT_EQ(InitVectorOfPrimes(6), outVec);
}
TEST(InitVectorOfPrimes, InputValue_10)
{
    std::vector<bool> outVec = { false, false, true, true, false, true, false, true, false, false, false };
    EXPECT_EQ(InitVectorOfPrimes(10), outVec);
}


TEST(GeneratePrimeNumbersSet, InputValue_2) 
{
    std::set<int> outSet = { 2 };
    EXPECT_EQ(GeneratePrimeNumbersSet(2), outSet);
}

TEST(GeneratePrimeNumbersSet, InputValue_23)
{
    std::set<int> outSet = { 2, 3, 5, 7, 11, 13, 17, 19, 23};
    EXPECT_EQ(GeneratePrimeNumbersSet(23), outSet);
}
