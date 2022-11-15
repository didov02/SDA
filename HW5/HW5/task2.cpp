#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <queue>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int N, K;
    cin >> N >> K;

    queue<long long int> queue;
    for (int i = 0; i < N; i++)
    {
        long long int num;
        cin >> num;
        queue.push(num);
    }

    long long int sum = 0;

    std::list<long long int> list;
    std::list<long long int> minArr;

    while (queue.size() != 0)
    {
        if (minArr.size() < K)
        {
            long long int num = queue.front();

            if (minArr.size() == 0)
            {
                minArr.push_back(num);
                list.push_back(num);
            }
            else
            {
                minArr.push_back(num);

                while (true)
                {
                    if (list.size() == 0)
                    {
                        list.push_back(num);
                        break;
                    }

                    long long int lastNum = list.back();

                    if (lastNum > num)
                    {
                        list.pop_back();
                    }
                    else
                    {
                        list.push_back(num);
                        break;
                    }
                }
            }

            queue.pop();
        }
        else if (minArr.size() == K)
        {
            int firstListNum = list.front();
            int firstArrNum = minArr.front();

            if (firstListNum == firstArrNum)
            {
                sum += firstListNum;
                list.pop_front();
                minArr.pop_front();
            }
            else
            {
                sum += firstListNum;
                minArr.pop_front();
            }
        }
    }

    int firstListNum = list.front();
    sum += firstListNum;

    cout << sum << '\n';
}