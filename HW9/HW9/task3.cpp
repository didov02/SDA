#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    string firstString, secondString;
    cin >> firstString >> secondString;

    size_t maxSize = 0;
    size_t tempSize = 0;

    if (firstString.size() > secondString.size())
    {
        for (size_t i = 0; i < firstString.size(); i++)
        {
            for (size_t j = 0; j < secondString.size(); j++)
            {
                if (firstString[i] == secondString[j])
                {
                    tempSize++;
                    size_t tempI = i + 1;
                    size_t tempJ = j + 1;

                    while ((tempI < firstString.size()) && (tempJ < secondString.size()))
                    {
                        if (firstString[tempI] == secondString[tempJ])
                        {
                            tempSize++;
                            tempI++;
                            tempJ++;
                        }
                        else
                            break;
                    }

                    if (tempSize > maxSize)
                        maxSize = tempSize;

                    tempSize = 0;
                }
            }
        }
    }
    else
    {
        for (size_t i = 0; i < secondString.size(); i++)
        {
            for (size_t j = 0; j < firstString.size(); j++)
            {
                if (secondString[i] == firstString[j])
                {
                    tempSize++;
                    size_t tempI = i + 1;
                    size_t tempJ = j + 1;

                    while ((tempI < secondString.size()) && (tempJ < firstString.size()))
                    {
                        if (secondString[tempI] == firstString[tempJ])
                        {
                            tempSize++;
                            tempI++;
                            tempJ++;
                        }
                        else
                            break;
                    }

                    if (tempSize > maxSize)
                        maxSize = tempSize;

                    tempSize = 0;
                }
            }
        }
    }

    cout << maxSize << '\n';
}