#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
using namespace std;


int main()
{
    set<long long int> s;
    list<long long int> l;

    long long int N, num;
    cin >> N;

    long long int max = 0;
    long long int count = 0;

    for (long long int j = 0; j < N; j++)
    {
        cin >> num;

        if (s.count(num) == 0)
        {
            l.push_back(num);
            s.insert(num);
            count++;
        }
        else
        {
            if (max < count)
                max = count;

            while (true)
            {
                if (l.front() == num)
                {
                    s.erase(l.front());
                    l.pop_front();
                    count--;
                    break;
                }

                s.erase(l.front());
                l.pop_front();
                count--;
            }

            l.push_back(num);
            s.insert(num);
            count++;
        }
    }

    if (count > max)
        max = count;

    cout << max << '\n';
}