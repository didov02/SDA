#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>
using namespace std;

void dfs(unordered_map<int, vector<int>>& list, unordered_map<int, set<int>>& components, unordered_set<int>& visited, unordered_map<int, int>& compare,
    int node, int component)
{
    if (visited.count(node) == 0)
    {
        compare[node] = component;
        visited.insert(node);
    }

    if (components[component].count(node) == 0)
        components[component].insert(node)a;

    for (auto child : list[node])
    {
        if (visited.count(child) == 0)
            dfs(list, components, visited, compare, child, component);
    }
}

void findconnectedcomponents(unordered_map<int, vector<int>>& list, unordered_map<int, set<int>>& components, unordered_map<int, int>& compare)
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
    size_t edges, roots;
    cin >> edges >> roots;

    unordered_map<int, vector<int>> list;
    int from, to;

    for (size_t i = 0; i < roots; i++)
    {
        if (list.size() > edges)
            return -1;

        cin >> from >> to;
        list[from].push_back(to);
        list[to].push_back(from);
    }

    unordered_map<int, set<int>> components;
    unordered_map<int, int> compare;
    findconnectedcomponents(list, components, compare);

    size_t inputs;
    cin >> inputs;

    vector<int> answer;

    for (size_t i = 0; i < inputs; i++)
    {
        cin >> from >> to;

        if (compare[from] == compare[to])
            answer.push_back(1);
        else
            answer.push_back(0);
    }

    for (size_t i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }

    cout << '\n';

}