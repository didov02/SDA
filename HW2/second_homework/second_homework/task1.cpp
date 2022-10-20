#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>



int main() {

    int N;
    std::cin >> N;

    auto vec = std::vector<int>(N);
    for (int& element : vec)
    {
        std::cin >> element;
    }

    for (int i = 0; i < N; i++)
    {
        if (vec[i] % 2 == 0)
            printf("%d\n", vec[i]);
    }

    for (int i = 0; i < N; i++)
    {
        if (vec[i] % 2 != 0)
        {
            printf("%d\n", vec[i]);
        }

    }
    return 0;
}