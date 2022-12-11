#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main() 
{
    size_t K, T, B;
    cin >> K >> T >> B;

    priority_queue < size_t, vector<size_t>, greater<size_t>> pq;

    size_t N, number;
    size_t currentT = 0;
    size_t groups = 0;
    cin >> N;

    for (size_t i = 1; i <= N; i++)
    {
        cin >> number;
       
        if (groups == B)
            break;
        
        currentT++;
        pq.push(number);

        if (currentT == T)
        {
            currentT = 0;
            groups++;

            for (size_t j = 0; j < K; j++)
            {
                cout << pq.top() << " ";
                pq.pop();
            }
        }
    }


    while (groups != B)
    {
        for (size_t i = 0; i < K; i++)
        {
            cout << pq.top() << " ";
            pq.pop();
        }

        groups++;
    }
}
