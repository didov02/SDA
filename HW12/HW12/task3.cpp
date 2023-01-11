#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

struct Edge
{
    int from;
    int to;
    int weight;

    bool operator<(const Edge& e1)
    {
        return this->weight < e1.weight;
    }
};

int findRoot(int node, vector<int>& parents) {
    if (parents[node] == node) {
        return node;
    }

    parents[node] = findRoot(parents[node], parents);
    return parents[node];
}

void kruskal(vector<Edge>& edges, int nodesCount, vector<Edge>& mstEdges) 
{
    sort(edges.begin(), edges.end());
    vector<int> parents(nodesCount+1);
    for (int i = 0; i < parents.size(); ++i) {
        parents[i] = i;
    }

    for (auto const& edge : edges) {
        int fromRoot = findRoot(edge.from, parents);
        int toRoot = findRoot(edge.to, parents);
        if (fromRoot != toRoot) {
            mstEdges.push_back(edge);

            parents[fromRoot] = toRoot;
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<Edge> graph;

    int from, to, weight;

    for (int i = 1; i <= M; i++)
    {
        cin >> from >> to >> weight;
        
        graph.push_back({ from,to,weight });
    }

    int max = 1000000000;
    int min = 0;

    for (int i = 0; i < M; i++)
    {
        vector<Edge> mstEdges;
        kruskal(graph, N, mstEdges);
        int tempMin = mstEdges[0].weight;
        int tempMax = mstEdges[mstEdges.size() - 1].weight;

        if (tempMax - tempMin < max - min)
        {
            max = tempMax;
            min = tempMin;
        }

        graph[0].weight = 1000000;
    }
   
    cout << min << " " << max << '\n';

}
