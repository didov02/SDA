#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int MINIMUM = INT_MIN;
const int MAXIMUM = INT_MAX;

struct Node
{
    Node* left;
    Node* right;
    int value;

    Node(int value, Node* left = nullptr, Node* right = nullptr)
    {
        this->value = value;
        this->left = left;
        this->right = right;
    }
};

bool check(Node* root, int min, int max)
{
    if (root == nullptr)
        return true;

    if (root->value < min || root->value > max)
        return false;

    if (check(root->left, min, root->value - 1))
        if (check(root->right, root->value + 1, max))
            return true;

    return false;
}

int isBST(Node* root)
{
    if (check(root, MINIMUM, MAXIMUM))
        return 1;

    return 0;
}

int main()
{
    int T;
    cin >> T;

    for (int k = 0; k < T; k++)
    {
        int N;
        cin >> N;

        int value, leftIndex, rightIndex;

        auto vec = vector<Node*>(3000000);

        Node* root = nullptr;

        for (int i = 0; i < N; i++)
        {
            cin >> value >> leftIndex >> rightIndex;

            if (root == nullptr)
            {
                root = new Node(value);
                vec[i] = root;
            }
            else
            {
                vec[i]->value = value;
            }

            if (leftIndex != -1)
            {
                vec[i]->left = new Node(0);
                vec[leftIndex] = vec[i]->left;
            }


            if (rightIndex != -1)
            {
                vec[i]->right = new Node(0);
                vec[rightIndex] = vec[i]->right;
            }
        }

        std::cout << isBST(vec[0]) << '\n';

        vec.clear();
    }
}