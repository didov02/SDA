#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 10000000;

void findWay(int** dist, int size)
{
    for (int i = 0; i < size; i++) {
        
        for (int j = 0; j < size; j++) {
            
            for (int p = 0; p < size; p++) {
               
                if (dist[j][i] + dist[i][p] < dist[j][p])
                    dist[j][p] = dist[j][i] + dist[i][p];
            }
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numberOfEdges, numberOfVertices, requestsCount, from, to, distance;
    cin >> numberOfVertices >> numberOfEdges >> requestsCount;

    int** matrix = new int*[numberOfVertices];
    for (int i = 0; i < numberOfVertices; i++)
    {
        matrix[i] = new int[numberOfVertices];
        for (int j = 0; j < numberOfVertices; j++)
        {
            if (i == j)
                matrix[i][j] = 0;
            else
                matrix[i][j] = MAX;
        }
    }

    for (int i = 0; i < numberOfEdges; i++)
    {
        cin >> from >> to >> distance;

        if (distance < matrix[from][to])
            matrix[from][to] = distance;
    }

    findWay(matrix, numberOfVertices);

    for (int i = 0; i < requestsCount; i++)
    {
        cin >> from >> to;

        if (matrix[from][to] == MAX)
            printf("%d\n", -1);
        else
            printf("%d\n", matrix[from][to]);
    }

    for (int i = 0; i < numberOfVertices; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}