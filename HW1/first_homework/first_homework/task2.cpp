#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int size;
	std::cin >> size;

	auto vec = std::vector<int>(size);
	for (int& element : vec)
	{
		std::cin >> element;
	}

	int sum = 0;

	int buyingIndex = 0;
	int sellingIndex = 0;
	bool areWeBuying = false;

	for (int i = 0; i < size; i++)
	{
		if (i == size - 1)
		{
			if (areWeBuying == true)
			{
				sellingIndex = i;
				sum += vec[sellingIndex] - vec[buyingIndex];
			}
			else
				break;
		}
		else if (vec[i] < vec[i + 1])
		{
			if (areWeBuying == false)
			{
				areWeBuying = true;
				buyingIndex = i;
			}
		}
		else if (vec[i] > vec[i + 1] && areWeBuying == true)
		{
			sellingIndex = i;
			sum += vec[sellingIndex] - vec[buyingIndex];

			areWeBuying = false;
		}
	}

	std::cout << sum << std::endl;

	return 0;
}