#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <stack>
using namespace std;

void topologicalSort(char start, unordered_map<char, vector<char>> al, unordered_map<char, bool>& visited, stack<char>& s)
{
    visited[start] = 1;
    for (auto kid : al[start])
    {
        if (!visited[kid])
            topologicalSort(kid, al, visited, s);
    }

    s.push(start);
}

int main()
{
    unordered_map<char, vector<char>> list;
    unordered_map<char, bool> visited;
    stack<char> s;
    char firstLetter = '/';

    int N;
    cin >> N;
    string word;
    string previousWord = "";

    for (int i = 0; i < N - 1; i++)
    {
        cin >> word;

        if (i == 0)
            firstLetter = word[0];

        if (previousWord == "")
        {
            string secondWord;
            cin >> secondWord;

            for (int j = 0; j < word.size(); j++)
            {
                if (j > secondWord.size())
                    break;

                if (word[j] != secondWord[j])
                {
                    char letter = word[j];
                    visited[letter] = 0;
                    list[letter].push_back(secondWord[j]);
                    break;
                }
            }

            previousWord = secondWord;
        }
        else
        {
            for (int j = 0; j < previousWord.size(); j++)
            {
                if (j > word.size())
                    break;

                if (previousWord[j] != word[j])
                {
                    char letter = previousWord[j];
                    visited[letter] = 0;
                    list[letter].push_back(word[j]);
                    break;
                }
            }

            previousWord = word;
        }
    }

    topologicalSort(firstLetter, list, visited, s);

    for (auto iter = list.begin(); iter != list.end(); iter++)
    {
        if (!visited[iter->first])
            topologicalSort(iter->first, list, visited, s);
    }

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
