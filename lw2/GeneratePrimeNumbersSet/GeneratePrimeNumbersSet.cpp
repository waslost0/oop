#include <iostream>
#include <set>
#include "Primes.h"

/*
Решето Эратосфена — это алгоритм, позволяющий найти все простые числа в отрезке [1; n] за O (n \log \log n) операций.

Идея проста — запишем ряд чисел 1 \ldots n, и будем вычеркивать сначала все числа, делящиеся на 2, кроме самого числа 2, затем деляющиеся на 3, кроме самого числа 3, затем на 5, затем на 7, 11, и все остальные простые до n.
Этот код сначала помечает все числа, кроме нуля и единицы, как простые, а затем начинает процесс отсеивания составных чисел. Для этого мы перебираем в цикле все числа от 2 до n, и, если текущее число i простое, то помечаем все числа, кратные ему, как составные.

При этом мы начинаем идти от i^2, поскольку все меньшие числа, кратные i, обязательно имеют простой делитель меньше i, а значит, все они уже были отсеяны раньше. (Но поскольку i^2 легко может переполнить тип int, в коде перед вторым вложенным циклом делается дополнительная проверка с использованием типа long~long.)
*/

void PrintPrimeNumbers(std::set<int>& primes)
{
	for (auto prime : primes)
	{
		std::cout << prime << " ";
	}
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << ERROR_NOT_ENOUGH_ARGUMENTS << std::endl;
		return 1;
	}

	int upperBound;

	try
	{
		upperBound = std::stoi(argv[1]);
	}
	catch (const std::invalid_argument&)
	{
		std::cerr << ERROR_VALUE_NUMBER << std::endl;
		return 1;
	}

	if ((upperBound <= 0) || (upperBound > MAX_SIZE))
	{
		std::cerr << ERROR_VALUE_NUMBER << std::endl;
		return 1;
	}

	if (upperBound < 2)
	{
		return 1;
	}

	std::set<int> prime = GeneratePrimeNumbersSet(upperBound);

	PrintPrimeNumbers(prime);

	return 0;
}