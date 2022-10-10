#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	size_t N;
	std::cin >> N;

	auto vec = std::vector<int>(N);
	for (int& element : vec)
	{
		std::cin >> element;
	}

	std::sort(vec.begin(), vec.end());

	int searchingNumber = 1;
	bool noDistance = true;
	bool havePositive = false;
	bool isBiggerThanOne = false;
	size_t counter = 0;

	for (size_t i = 0; i < N; i++)
	{
		if (vec[i] > 0)
		{
			havePositive = true;

			if (vec[counter] > 1)
			{
				isBiggerThanOne = true;
				break;
			}

			if (i + 1 >= N)
				break;

			if (vec[i + 1] - vec[i] > 1)
			{
				searchingNumber = vec[i] + 1;
				noDistance = false;
				break;
			}
		}

		if (havePositive == false)
			counter++;
	}


	if (noDistance == true && havePositive == true && isBiggerThanOne == false)
	{
		searchingNumber = vec[vec.size() - 1] + 1;
	}

	std::cout << searchingNumber << std::endl;
}