#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Tournament
{
    unsigned long long max;
    unsigned long long min;
    unsigned long long players;
};

void merge(std::vector<unsigned long long>& arr, int left, int mid, int right)
{
    int firstLength = mid + 1 - left;
    int secondLength = right - mid;

    int* leftArr = new int[firstLength];
    int* rightArr = new int[secondLength];

    for (int i = 0; i < firstLength; i++)
        leftArr[i] = arr[left + i];

    for (int i = 0; i < secondLength; i++)
        rightArr[i] = arr[mid + 1 + i];

    int firstArrIndex = 0;
    int secondArrIndex = 0;
    int mergeArrIndex = left;

    while (firstArrIndex < firstLength && secondArrIndex < secondLength)
    {
        if (leftArr[firstArrIndex] < rightArr[secondArrIndex])
            arr[mergeArrIndex++] = leftArr[firstArrIndex++];
        else
            arr[mergeArrIndex++] = rightArr[secondArrIndex++];
    }

    while (firstArrIndex < firstLength)
        arr[mergeArrIndex++] = leftArr[firstArrIndex++];

    while (secondArrIndex < secondLength)
        arr[mergeArrIndex++] = rightArr[secondArrIndex++];

    delete[] leftArr;
    delete[] rightArr;
}

void mergeSort(std::vector<unsigned long long>& arr, int begin, int end)
{
    if (begin >= end)
        return;

    int mid = (begin + end) / 2;
    mergeSort(arr, begin, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, begin, mid, end);
}

int main() {

    unsigned long long students, tournamentsCount;
    std::cin >> students >> tournamentsCount;

    auto weights = std::vector<unsigned long long>(students);

    for (unsigned long long i = 0; i < students; i++)
    {
        std::cin >> weights[i];
    }

    mergeSort(weights, 0, students - 1);

    Tournament* tournaments = new Tournament[tournamentsCount];
    for (unsigned long long i = 0; i < tournamentsCount; i++)
    {
        std::cin >> tournaments[i].min >> tournaments[i].max;
    }

    for (unsigned long i = 0; i < tournamentsCount; i++)
    {
        unsigned long long currentMin = tournaments[i].min;
        unsigned long long currentMax = tournaments[i].max;

        if (currentMin > currentMax)
            tournaments[i].players = 0;
        else
        {
            vector<unsigned long long>::iterator beginElement = lower_bound(weights.begin(), weights.end(), currentMin);
            int startIndex = beginElement - weights.begin();

            vector<unsigned long long>::iterator endElement = upper_bound(weights.begin(), weights.end(), currentMax);
            int endIndex = (endElement - weights.begin()) - 1;

            tournaments[i].players = endIndex - startIndex + 1;
        }

        printf("%llu\n", tournaments[i].players);
    }

    return 0;
}