#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t N;
    cin >> N;

    priority_queue<double> max;
    priority_queue<double, vector<double>, greater<double>> min;

    vector<double> print;

    double number;

    for (size_t i = 0; i < N; i++)
    {
        cin >> number;

        if (max.empty() && min.empty())
        {
            max.push(number);
            cout << setprecision(1) << fixed << number << '\n';
        }
        else if (max.size() > min.size())
        {
            if (max.top() > number)
            {
                double temp = max.top();
                max.pop();
                min.push(temp);
                max.push(number);
            }
            else
            {
                min.push(number);
            }

            double print = (max.top() + min.top()) / 2;
            cout << setprecision(1) << fixed << print << '\n';
        }
        else if (max.size() == min.size())
        {
            if (number > min.top())
            {
                double temp = min.top();
                min.pop();
                max.push(temp);
                min.push(number);
            }
            else
            {
                max.push(number);
            }

            cout << setprecision(1) << fixed << max.top() << '\n';
        }
    }
}