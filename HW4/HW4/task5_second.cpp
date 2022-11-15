#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int previous = 100000;

void shooting(std::vector<int>& vec, int position, int value, int& count, int& ballsDeleted)
{
	int startIndex = position;
	int endIndex = position;

	while (vec[startIndex] == value)
	{
		if (startIndex == 0)
			break;
		else if (vec[startIndex - 1] == value)
			startIndex--;
		else
			break;
	}

	while (vec[endIndex] == value)
	{
		if (endIndex == vec.size() - 1)
			break;
		else if (vec[endIndex + 1] == value)
			endIndex++;
		else
			break;
	}

	if (endIndex - startIndex + 1 >= 3)
	{
		int temp = 0;
		while (temp <= endIndex - startIndex)
		{
			vec.erase(vec.begin() + startIndex);
			count--;
			ballsDeleted++;
			temp++;
		}

		if (vec.empty())
			return;
		else if (vec[startIndex - 1] == vec[startIndex])
		{
			shooting(vec, startIndex, vec[startIndex], count, ballsDeleted);
		}
	}

	previous = startIndex;
}

bool isPushedBack(std::vector<int> vec, int position)
{
	for (int& element : vec)
	{
		if (element == position)
			return true;
	}

	return false;
}

int main()
{
	int ballsCount;
	std::cin >> ballsCount;

	std::vector<int> vec;
	std::vector<int> pushedBackIndexes;

	for (int i = 0; i < ballsCount; i++)
	{
		int num;
		std::cin >> num;

		vec.push_back(num);
	}

	int requests;
	std::cin >> requests;

	int originalBallsCount = ballsCount;
	int ballsDeleted = 0;
	int index = 0;

	int count = 0;

	for (int i = 0; i < requests; i++)
	{
		int currentPosition, currentValue;
		std::cin >> currentPosition >> currentValue;

		if (ballsCount <= 0)
		{
			std::cout << "Game Over" << '\n';
		}
		else
		{
			if (currentPosition >= originalBallsCount - 1)
			{
				if (isPushedBack(pushedBackIndexes, currentPosition))
					vec.insert(vec.begin() + currentPosition + 1 + pushedBackIndexes.size(), currentValue);
				else
				{
					vec.push_back(currentValue);
					pushedBackIndexes.push_back(currentPosition);
				}
					
				
				currentPosition = ballsCount - 1 - pushedBackIndexes.size();
			}
			else
			{
				if (previous < currentPosition)
					vec.insert(vec.begin() + currentPosition + 1 + count, currentValue);
				else
					vec.insert(vec.begin() + currentPosition + 1, currentValue);
			}

			ballsCount++;
			count++;

			if (previous < currentPosition && ballsCount < originalBallsCount)
				shooting(vec, currentPosition + count + 1, currentValue, count, ballsDeleted);
			else
				shooting(vec, currentPosition + 1, currentValue, count, ballsDeleted);

			ballsCount -= ballsDeleted;

			std::cout << ballsDeleted << '\n';

			ballsDeleted = 0;
		}
	}

	if (ballsDeleted >= ballsCount)
	{
		std::cout << -1 << '\n';
	}
	else
	{
		for (int& value : vec)
		{
			std::cout << value << " ";
		}

		std::cout << '\n';
	}
}