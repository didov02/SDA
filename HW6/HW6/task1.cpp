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
    long long int value;
    long long int x;
    long long int y;

    Node(long long int value, long long int x = 0, long long int y = 0, Node* left = NULL, Node* right = NULL)
    {
        this->value = value;
        this->left = left;
        this->right = right;
        this->x = x;
        this->y = y;
    }
};

int main()
{
    long long int N;
    cin >> N;

    vector<Node*> arr;
    queue<Node*> queue;

    long long int minX = 0;
    long long int maxX = 0;

    for (long long int i = 0; i < N; i++)
    {
        long long int value, leftIndex, rightIndex;
        cin >> value >> leftIndex >> rightIndex;

        Node* root = nullptr;
        if (queue.empty())
        {
            root = new Node(value);
            queue.push(root);
            arr.push_back(root);
        }
        else
        {
            root = queue.front();
        }

        if(i != 0)
            root->value = value;
        
        long long int x = root->x;
        long long int y = root->y;

        if (leftIndex != -1)
        {
            root->left = new Node(0, x - 1, y + 1);

            if (minX > x - 1)
                minX = x - 1;

            queue.push(root->left);
            arr.push_back(root->left);
        }


        if (rightIndex != -1)
        {
            root->right = new Node(0, x + 1, y + 1);

            if (maxX < x + 1)
                maxX = x + 1;
                
            queue.push(root->right);
            arr.push_back(root->right);
        }

        queue.pop();
    }

    long long int counter = 0;
    long long int sum = 0;

    while (minX <= maxX)
    {
        if (counter > arr.size() - 1)
        {
            counter = 0;
            std::cout << sum << " ";
            sum = 0;
            minX++;
            continue;
        }

        if (arr[counter]->x == minX)
            sum += arr[counter]->value;

        counter++;
    }
}