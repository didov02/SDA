//unfinished

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long developers[100000];

bool isOdd(unsigned long long num)
{
    if (num % 2 == 0)
        return false;

    return true;
}

unsigned long long arrSum(unsigned long long arr[], unsigned long long size)
{
    unsigned long long sum = 0;

    for (unsigned long long i = 0; i < size; i++)
        sum += arr[i];

    return sum;
}

void getSum(unsigned long long& sum, unsigned long long arr[], unsigned long long count, unsigned long long teams,
    unsigned long long previousArrSum, unsigned long long currentArrSum, unsigned long long& counterForDevelopers,
    bool check)
{
    unsigned long long mid = 0;

    if (check)
    {
        if (count % 2 == 0)
            mid = count / 2;
        else
            mid = count / 2 + 1;
    }
    else
        mid = count / 2;

    unsigned long long firstArrLength = mid;
    unsigned long long secondArrLength = count - mid;

    unsigned long long* firstArr = new unsigned long long[firstArrLength];
    unsigned long long* secondArr = new unsigned long long[secondArrLength];

    for (unsigned long long i = 0; i < mid; i++)
        firstArr[i] = arr[i];

    for (unsigned long long i = 0; i < (count - mid); i++)
        secondArr[i] = arr[mid + i];

    unsigned long long firstArrSum = arrSum(firstArr, firstArrLength);
    unsigned long long secondArrSum = arrSum(secondArr, secondArrLength);

    if (teams == 1)
    {
        unsigned long long saveIndex = 0;

        for (unsigned long long i = 0; i < count - 1; i++)
        {
            currentArrSum -= arr[i];

            if (previousArrSum + arr[i] < currentArrSum)
            {
                previousArrSum += arr[i];
                saveIndex = i + 1;
            }
            else
            {
                saveIndex = i;
                break;
            }
        }

        for (unsigned long long i = saveIndex; i < count; i++)
        {
            sum += arr[i];
            counterForDevelopers++;
        }
    }
    else if (teams != 0)
    {
        teams--;

        if (firstArrSum > secondArrSum)
        {
            getSum(sum, firstArr, mid, teams, secondArrSum, firstArrSum, counterForDevelopers, check);
        }
        else
        {
            getSum(sum, secondArr, count - mid, teams, firstArrSum, secondArrSum, counterForDevelopers, check);
        }
    }

    delete[] firstArr;
    delete[] secondArr;
}

int main() {
    unsigned long long developersCount, teams;
    std::cin >> developersCount >> teams;

    for (unsigned long long i = 0; i < developersCount; i++)
        std::cin >> developers[i];

    std::sort(developers, developers + developersCount);

    unsigned long long sum = 0;

    if (teams > developersCount)
    {
        printf("%llu\n", sum);

        return 0;
    }
    else if (teams == 1)
    {
        for (unsigned long long i = 0; i < developersCount; i++)
        {
            sum += developers[i];
        }

        printf("%llu\n", sum);
        return 0;
    }

    bool areDevelopersOdd = isOdd(developersCount);

    if (areDevelopersOdd)
    {
        unsigned long long counterForSpecial = 0;
        unsigned long long counterForUnspecial = 0;
        unsigned long long newSum = 0;

        bool special = true;
        getSum(newSum, developers, developersCount, teams, 0, 0, counterForSpecial, special);

        special = false;
        getSum(sum, developers, developersCount, teams, 0, 0, counterForUnspecial, special);

        if (counterForSpecial < counterForUnspecial)
            sum = newSum;
        else if (counterForSpecial == counterForUnspecial)
        {
            if (newSum > sum)
                sum = newSum;
        }
    }
    else
    {
        unsigned long long uselessCounter = 0;
        bool check = false;
        getSum(sum, developers, developersCount, teams, 0, 0, uselessCounter, check);
    }

    printf("%llu\n", sum);

    return 0;
}