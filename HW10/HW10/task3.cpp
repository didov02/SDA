#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
using namespace std;

void bfs(unordered_map<int, unordered_set<int>>& list, unordered_map<int, int>& notConnected, int startingRoot, unordered_set<int>& visited)
{
    queue<int> q;
    visited.insert(startingRoot);
    q.push(startingRoot);
    notConnected[startingRoot] = 0;

    while (!q.empty())
    {
        for (auto iter = list.begin(); iter != list.end(); iter++)
        {
            if (visited.count((*iter).first) == 0)
            {
                if (list[q.front()].count((*iter).first) == 0)
                {
                    visited.insert((*iter).first);
                    notConnected[(*iter).first] = notConnected[q.front()] + 1;
                    q.push((*iter).first);
                }
            }
        }

        q.pop();
    }
}

void dfs(unordered_map<int, unordered_set<int>>& list, unordered_map<int, set<int>>& components, unordered_set<int>& visited, unordered_map<int, int>& compare,
    int node, int component)
{
    if (visited.count(node) == 0)
    {
        compare[node] = component;
        visited.insert(node);
    }

    if (components[component].count(node) == 0)
        components[component].insert(node);

    for (auto child : list[node])
    {
        if (visited.count(child) == 0)
            dfs(list, components, visited, compare, child, component);
    }
}

void findConnectedComponents(unordered_map<int, unordered_set<int>>& list, unordered_map<int, set<int>>& components, unordered_map<int, int>& compare)
{
    unordered_set<int> visited;
    int component = 0;

    for (auto iter = list.begin(); iter != list.end(); iter++)
    {
        if (visited.count((*iter).first) == 0)
        {
            component++;
            dfs(list, components, visited, compare, (*iter).first, component);
        }

    }
}

int main() 
{
    int requests, roots, edges, startingRoot, from, to;
    cin >> requests;

    for (int i = 0; i < requests; i++)
    {
        unordered_map<int, unordered_set<int>> list;

        cin >> roots >> edges;

        for (int j = 0; j < roots; j++)
        {
            list[j + 1];
        }

        for (int j = 0; j < edges; j++)
        {
            if (list.size() > roots)
                return -1;

            cin >> from >> to;
            list[from].insert(to);
            list[to].insert(from);
        }

        unordered_map<int, set<int>> components;
        unordered_map<int, int> compare;
        findConnectedComponents(list, components, compare);

        map<int, int> answer;
        unordered_map<int, int> notConnectedLevels;

        cin >> startingRoot;

        unordered_set<int> visited;
        if (components.size() == 1)
        {
            bfs(list, notConnectedLevels, startingRoot, visited);

            for (auto iter = list.begin(); iter != list.end(); iter++)
            {
                if ((*iter).first == startingRoot)
                    continue;

                answer[(*iter).first] = notConnectedLevels[(*iter).first];
            }

            for (int i = 1; i <= roots; i++)
            {
                if (i == startingRoot)
                    continue;

                if (answer.count(i) == 0)
                    cout << -1 << " ";
                else
                    cout << answer[i] << " ";
            }
        }
        else
        {
            for (int i = 1; i <= roots; i++)
            {
                if (i == startingRoot)
                    continue;

                if (compare[i] == compare[startingRoot] && (list[startingRoot].count(i) == 1))
                    cout << 2 << " ";
                else
                    cout << 1 << " ";
            }
        }

        
        cout << '\n';
    }

    
}