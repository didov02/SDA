#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

struct Edge
{
    int from;
    int to;
    int cost;
    int profit;
    int index;

    bool operator<(const Edge& e1)
    {
        if (this->cost == e1.cost)
            return this->profit > e1.profit;

        return this->cost < e1.cost;
    }
};


int findRoot(int node, vector<int>& parents) {
    if (parents[node] == node) {
        return node;
    }

    parents[node] = findRoot(parents[node], parents);
    return parents[node];
}

void kruskal(vector<Edge>& edges, int nodesCount, vector<Edge>& mstEdges) {
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
    int nodes, edges;
    cin >> nodes >> edges;

    vector<Edge> graph;

    int from, to, cost, profit;

    for (int i = 0; i < edges; i++)
    {
        cin >> from >> to >> cost >> profit;

        graph.push_back({ from,to,cost,profit,i + 1 });
    }

    vector<Edge> mstEdges;
    kruskal(graph, nodes, mstEdges);
    
    for (auto const& edge : mstEdges) {
        cout << edge.index << endl;
    }
}