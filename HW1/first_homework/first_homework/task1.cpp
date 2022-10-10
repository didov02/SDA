#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	size_t Q;
	std::cin >> Q;

	for (size_t i = 0; i < Q; i++)
	{
		int size;
		std::cin >> size;

		auto vec = std::vector<char>(size);
		for (char& element : vec)
		{
			std::cin >> element;
		}
		
		size_t counter = 0;

		for (size_t j = vec.size() - 1; j > 0; j--)
		{
			if (vec[j] == vec[j - 1])
			{
				vec.pop_back();
				counter++;
			}
		}

		std::cout << counter << std::endl;
	}
}