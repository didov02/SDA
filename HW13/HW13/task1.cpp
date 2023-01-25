#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int MAX_NUMBER = 10080;
const long long int DIVIDE_BY = 1000000007;

long long int getCount(vector<int>& nums)
{
    long long int count = 0;

    unordered_map<long long int, long long int> currentMap;
    currentMap[0] = 1;

    for (int i = 0; i < nums.size(); i++)
    {
        unordered_map<long long int, long long int> tempMap;

        for (auto const& element : currentMap)
        {
            if (element.first + nums[i] <= MAX_NUMBER)
            {
                if (tempMap.count(element.first + nums[i]) == 0)
                    tempMap[element.first + nums[i]] = 1;
                else
                    tempMap[element.first + nums[i]]++;
            }
        }

        for (auto const& element : tempMap)
        {
            if (currentMap.count(element.first) == 0)
                currentMap[element.first] = element.second;
            else
                currentMap[element.first] += element.second;
        }
    }

    for (auto const& element : currentMap)
        count += element.second;

    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, number;
    cin >> N;

    vector<int> numbers;

    for (int i = 0; i < N; i++)
    {
        cin >> number;
        numbers.push_back(number);
    }

    long long int count = getCount(numbers) % DIVIDE_BY;
    cout << count << '\n';
}

