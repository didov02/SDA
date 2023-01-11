#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

const int INTMAX = 2147483647;
const int N = 100001;
int dist[N];
vector<pair<int, int>> adjacencyList[N];
unordered_map<int, int> timeWaiting;

void shortestPathDijkstra(int v, int end)
{
    for (int i = 0; i < N; i++) 
        dist[i] = INTMAX;

    dist[v] = 0;

    priority_queue< pair<int, int>, vector <pair<int, int>>, greater<pair<int, int>> > pq;
    pq.push({ v,0 });

    while (!pq.empty())
    {
        int current = pq.top().first;
        int costToCurrent = pq.top().second;
        pq.pop();

        for (pair<int, int> neighbour : adjacencyList[current])
        {
            int child = neighbour.first;
            int costToChildOfCurrent = neighbour.second;

			int time = costToCurrent + costToChildOfCurrent;

			if (child != end)
			{
				if (time % timeWaiting[child] != 0) {
					time += (timeWaiting[child] - time % timeWaiting[child]);
				}
			}

            if (dist[child] > time)
            {
                dist[child] = time;
                pq.push({ child, time });
            }

        }
    }
}

int main() 
{
	int numberOfEdges, numberOfVertices, costToChildOfCurrent, startingEdge, endingEdge, waiting;
	int from, to;
	cin >> numberOfVertices >> numberOfEdges >> startingEdge >> endingEdge;

	for (int i = 0; i < numberOfVertices; i++)
	{
		cin >> waiting;
		timeWaiting[i] = waiting;
	}

	while (numberOfEdges)
	{
		cin >> from >> to >> costToChildOfCurrent;
		adjacencyList[from].push_back({ to, costToChildOfCurrent });
		numberOfEdges--;
	}

	shortestPathDijkstra(startingEdge, endingEdge);

	if (dist[endingEdge] == INTMAX)
		cout << -1 << '\n';
	else
		cout << dist[endingEdge] << '\n';

	return 0;
}
