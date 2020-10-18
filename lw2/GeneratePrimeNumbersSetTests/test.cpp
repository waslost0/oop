#include "pch.h"
#include "../GeneratePrimeNumbersSet/Primes.cpp"

TEST(InitVectorOfPrimesTest1, InputValue_2)
{
    std::vector<bool> outVec = { false, false, true };
    EXPECT_EQ(InitVectorOfPrimes(2), outVec);
}

TEST(InitVectorOfPrimesTest2, InputValue_6)
{
    std::vector<bool> outVec = { false, false, true, true, false, true, false };
    EXPECT_EQ(InitVectorOfPrimes(6), outVec);
}
TEST(InitVectorOfPrimesTest3, InputValue_10)
{
    std::vector<bool> outVec = { false, false, true, true, false, true, false, true, false, false, false };
    EXPECT_EQ(InitVectorOfPrimes(10), outVec);
}


TEST(GeneratePrimeNumbersSetTest1, InputValue_2) 
{
    std::set<int> outSet = { 2 };
    EXPECT_EQ(GeneratePrimeNumbersSet(2), outSet);
}

TEST(GeneratePrimeNumbersSetTest2, InputValue_23) 
{
    std::set<int> outSet = { 2, 3, 5, 7, 11, 13, 17, 19, 23};
    EXPECT_EQ(GeneratePrimeNumbersSet(23), outSet);
}

TEST(GeneratePrimeNumbersSetTest3, InputValue_100) 
{
    std::set<int> outSet = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29,31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
    EXPECT_EQ(GeneratePrimeNumbersSet(23), outSet);
}

