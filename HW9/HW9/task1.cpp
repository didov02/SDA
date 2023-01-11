#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <unordered_set>
using namespace std;

void setFullName(string& name, string parent)
{
    string tempName = "";

    if (parent == "/")
    {
        tempName = "/" + name + "/";
        name = tempName;
    }
    else
    {
        tempName = parent + name + "/";
        name = tempName;
    }
}

void ls(const unordered_map<string, unordered_set<string>>& um, string currentDirectory)
{
    auto findDirectory = um.find(currentDirectory);
    vector<string> v;

    v.insert(v.end(), um.at(currentDirectory).begin(), um.at(currentDirectory).end());
    std::sort(v.begin(), v.end());

    for (string& element : v)
        cout << element << " ";

    cout << '\n';
}

void cdWhenTwoPoints(string& currentDirectory, const unordered_map<string, string>& p)
{
    auto temp = p.find(currentDirectory);

    if (temp->second == "")
        cout << "No such directory\n";
    else
    {
        currentDirectory = temp->second;
    }
}

int main()
{
    unordered_map<string, unordered_set<string>> um;
    um["/"] = unordered_set<string>();

    int N;
    cin >> N;
    cin.ignore();

    string task, name;
    string currentDirectory = "/";

    unordered_map<string, string> parenting;
    parenting["/"] = "";

    for (int i = 0; i < N; i++)
    {
        cin >> task;

        if (task == "mkdir")
        {
            cin >> name;
            string fullName = name;
            setFullName(fullName, currentDirectory);

            if (um[currentDirectory].count(name) == 0)
            {
                um[fullName] = unordered_set<string>();
                um[currentDirectory].insert(name);
                parenting[fullName] = currentDirectory;
            }
            else
                cout << "Directory already exists\n";
        }
        else if (task == "ls")
        {
            ls(um, currentDirectory);
        }
        else if (task == "pwd")
        {
            cout << currentDirectory << '\n';
        }
        else if (task == "cd")
        {
            cin >> name;

            if (name == "..")
            {
                cdWhenTwoPoints(currentDirectory, parenting);
            }
            else
            {

                if (um[currentDirectory].count(name) == 0)
                {
                    cout << "No such directory\n";
                }
                else
                {
                    setFullName(name, currentDirectory);
                    currentDirectory = name;
                }
            }
        }
    }
}