#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int main() 
{
    int count, magicNumber;
    cin >> count >> magicNumber;

    unordered_map<int, int> um;
    unordered_map<int, int> search;

    for (int i = 0; i < count; i++)
    {
        cin >> search[i];
        um[search[i]]++;
    }

    unordered_map<int, int> seenNumbers;

    int sum = 0;

    for (int i = 0; i < count; i++)
    {
        int currentValue = search[i];
        um[currentValue]--;

        if (um[currentValue] <= 0)
            um.erase(currentValue);

        if (currentValue % magicNumber == 0)
        {
            if (seenNumbers.count(currentValue / magicNumber) == 1)
            {
                int firstNum = seenNumbers[currentValue / magicNumber];
                if (um.count(currentValue * magicNumber) == 1)
                {
                    int secondNum = um[currentValue * magicNumber];
                    sum += firstNum * secondNum;
                }
            }
        }

        seenNumbers[currentValue]++;
    }

    cout << sum << "\n";
}