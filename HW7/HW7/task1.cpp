#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

void addMasks(set<size_t>& s, size_t num, size_t checkNum)
{
    auto number = (num | checkNum);
    if (number == num)
    {
        if (s.count(checkNum) == 0)
            s.insert(checkNum);
    }

}

int main()
{
    size_t N, num;
    cin >> N;

    set<size_t> s;

    for (auto i = 0; i < N; i++)
    {
        cin >> num;
        for (auto k = 0; k <= num; k++)
            addMasks(s, num, k);
    }

    cout << s.size() << '\n';
}