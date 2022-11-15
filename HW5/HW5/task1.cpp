#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

struct Apple
{
    int row;
    int colomn;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, T;
    cin >> N >> M >> T;
    std::cin.ignore();

    int count = N * M;

    int** apples = new int* [N];
    for (int i = 0; i < N; i++)
    {
        apples[i] = new int[M];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            apples[i][j] = 0;
    }

    list<Apple> badApples;

    int currRow, currCol;
    cin >> currRow >> currCol;

    if (currRow <= N && currCol <= M && currRow > 0 && currCol > 0)
    {
        Apple currApp;
        currApp.row = --currRow;
        currApp.colomn = --currCol;

        badApples.push_back(currApp);

        apples[currRow][currCol] = 1;

        count--;
    }

    while (cin >> currRow >> currCol)
    {
        if (currRow <= N && currCol <= M && currRow > 0 && currCol > 0)
        {
            Apple currApp;
            currApp.row = --currRow;
            currApp.colomn = --currCol;

            badApples.push_back(currApp);

            apples[currRow][currCol] = 1;

            count--;
        }

        break;
    }

    for (int i = 0; i < T; i++)
    {
        int badApplesCount = badApples.size();

        for (int j = 0; j < badApplesCount; j++)
        {
            Apple current = badApples.front();
            int currRow = current.row;
            int currColomn = current.colomn;

            if (currColomn - 1 < M && currColomn - 1 >= 0)
            {
                if (apples[currRow][currColomn - 1] == 0)
                {
                    apples[currRow][currColomn - 1] = 1;

                    Apple newApple;
                    newApple.row = currRow;
                    newApple.colomn = currColomn - 1;
                    badApples.push_back(newApple);

                    count--;
                }
            }
            if (currColomn + 1 < M)
            {
                if (apples[currRow][currColomn + 1] == 0)
                {
                    apples[currRow][currColomn + 1] = 1;

                    Apple newApple;
                    newApple.row = currRow;
                    newApple.colomn = currColomn + 1;
                    badApples.push_back(newApple);

                    count--;
                }
            }
            if (currRow + 1 < N)
            {
                if (apples[currRow + 1][currColomn] == 0)
                {
                    apples[currRow + 1][currColomn] = 1;

                    Apple newApple;
                    newApple.row = currRow + 1;
                    newApple.colomn = currColomn;
                    badApples.push_back(newApple);

                    count--;
                }
            }
            if (currRow - 1 < N && currRow - 1 >= 0)
            {
                if (apples[currRow - 1][currColomn] == 0)
                {
                    apples[currRow - 1][currColomn] = 1;

                    Apple newApple;
                    newApple.row = currRow - 1;
                    newApple.colomn = currColomn;
                    badApples.push_back(newApple);

                    count--;
                }
            }

            badApples.pop_front();
        }
    }

    cout << count << '\n';

    for (int i = 0; i < N; i++)
        delete[] apples[i];

    delete[] apples;

}