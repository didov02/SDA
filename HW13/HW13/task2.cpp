#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const long long int DIVIDE_BY = 1000000007;

long long int getNum(long long int n)
{
    long long int a = 2, b = 2;

    for (long long int i = 3; i <= n; i++) 
    {
        long long int c = (a + b) % DIVIDE_BY;
        a = b;
        b = c;
    }

    return b;
}

int main() 
{
    long long int N;
    cin >> N;

    if (N == 1 || N == 2)
        cout << 2 << '\n';
    else
    {
        long long int number = getNum(N);
        cout << number << '\n';
    }
}