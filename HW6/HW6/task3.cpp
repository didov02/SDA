#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Node
{
    Node* left;
    Node* right;
    Node* previous;
    int value;

    Node(int value, Node* previous = nullptr)
    {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
        this->previous = previous;
    }
};

bool checkFunc(Node* root, int target)
{
    if (root->value == target)
        return true;
    if (root->value < target)
        return false;
    if (root->previous == nullptr)
        return false;

    return checkFunc(root->previous, target);
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    Node* root = nullptr;
    int parent, child;

    auto vec = vector<Node*>(1000000);

    for (int i = 0; i < N - 1; i++)
    {
        cin >> parent >> child;

        if (vec[parent] == nullptr)
        {
            vec[parent] = new Node(parent);

            if (root == nullptr)
            {
                root = vec[parent];
            }
        }

        vec[child] = new Node(child, vec[parent]);
    }

    cin >> N;
    int firstNum, secondNum;

    bool check;

    for (int i = 0; i < N; i++)
    {
        cin >> firstNum >> secondNum;

        check = checkFunc(vec[secondNum], firstNum);
        if (check)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}