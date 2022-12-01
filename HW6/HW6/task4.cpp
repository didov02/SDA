#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Node {
    string value;
    Node* left;
    Node* right;

    Node(string value) {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinarySearchTree {
private:
    Node* root;

    Node* findElement(string element) {
        Node* current = this->root;

        while (current != nullptr) {
            if (current->value > element) {
                current = current->left;
            }
            else if (current->value < element) {
                current = current->right;
            }
            else {
                break;
            }
        }

        return current;
    }

    void preOrderCopy(Node* node) {
        if (node == nullptr) {
            return;
        }

        this->insert(node->value);
        this->preOrderCopy(node->left);
        this->preOrderCopy(node->right);
    }

    Node* insert(string element, Node* node) {
        if (node == nullptr) {
            node = new Node(element);
        }
        else if (element < node->value) {
            node->left = this->insert(element, node->left);
        }
        else if (element > node->value) {
            node->right = this->insert(element, node->right);
        }

        return node;
    }

    Node* getLeftMostNode(Node* root) {
        Node* current = root;
        while (current->left != nullptr) {
            current = current->left;
        }

        return current;
    }

    Node* remove(Node* node, string element) {
        if (node == nullptr) {
            return nullptr;
        }

        if (node->value > element) {
            node->left = remove(node->left, element);
        }
        else if (node->value < element) {
            node->right = remove(node->right, element);
        }
        else {
            if (node->left == nullptr) {
                return node->right;
            }
            else if (node->right == nullptr) {
                return node->left;
            }

            Node* leftMostNode = this->getLeftMostNode(node->right);
            node->value = leftMostNode->value;
            node->right = this->remove(node->right, leftMostNode->value);
        }

        return node;
    }

public:
    BinarySearchTree() {
        this->root = nullptr;
    }

    void insert(string element) {
        this->root = insert(element, this->root);
    }

    bool contains(string element) {
        Node* current = this->findElement(element);

        return current != nullptr;
    }

    void remove(string element) {
        if (this->root == nullptr) {
            return;
        }

        this->root = this->remove(this->root, element);
    }
};

int main() 
{
    int N;
    cin >> N;
    cin.ignore();

    BinarySearchTree tree;
    for (int i = 0; i < N; i++)
    {
        string current;
        cin >> current;

        tree.insert(current);
    }

    int Q;
    cin >> Q;
    cin.ignore();

    for (int i = 0; i < Q; i++)
    {
        string current;
        cin >> current;

        if (tree.contains(current))
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }


}