#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

struct Edge {
    int from;
    int to;
};

int findRoot(int node, vector<int>& parents) {
    if (parents[node] == node) {
        return node;
    }

    parents[node] = findRoot(parents[node], parents);
    return parents[node];
}

void kruskal(vector<Edge>& edges, int nodesCount, vector<int>& parents) {
    for (int i = 0; i < parents.size(); ++i) {
        parents[i] = i;
    }

    for (auto const& edge : edges) {
        int fromRoot = findRoot(edge.from, parents);
        int toRoot = findRoot(edge.to, parents);
        if (fromRoot != toRoot) {
            parents[fromRoot] = toRoot;
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nodes, edgesCount;
    cin >> nodes >> edgesCount;
    
    int from, to;

    vector<Edge> edges;
    for (int i = 0; i < edgesCount; i++) {
        cin >> from >> to;

        edges.push_back({from, to});
    }

    vector<int> parents(nodes+1);
    kruskal(edges, nodes, parents);

    int Q, question;
    cin >> Q;

    string answer;

    for (int i = 0; i < Q; i++)
    {
        cin >> question >> from >> to;

        if (question == 1)
        {
            int fromRoot = findRoot(from, parents);
            int toRoot = findRoot(to, parents);
            if (fromRoot == toRoot)
                answer += "1";
            else
                answer += "0";
        }
        else
        {
            int fromRoot = findRoot(from, parents);
            int toRoot = findRoot(to, parents);
            if (fromRoot != toRoot) {
                parents[fromRoot] = toRoot;
            }
        }
    }

    cout << answer << '\n';

    return 0;
}