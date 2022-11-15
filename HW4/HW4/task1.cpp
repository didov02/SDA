//#include <cmath>
//#include <cstdio>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//struct Node
//{
//    int data;
//    Node* next = nullptr;
//
//    Node(int data, Node* next = nullptr)
//    {
//        this->data = data;
//        this->next = next;
//    }
//};
//
//class List
//{
//private:
//    Node* head;
//    Node* tail;
//
//public:
//    List()
//    {
//        head = nullptr;
//        tail = nullptr;
//    }
//
//    void push_back(int num)
//    {
//        if (head == nullptr)
//        {
//            head = new Node(num);
//            tail = head;
//        }
//        else
//        {
//            tail->next = new Node(num);
//            tail = tail->next;
//        }
//    }
//
//    void push_front(int num)
//    {
//        Node* newNode = new Node(num, head);
//        head = newNode;
//
//        if (tail == nullptr)
//            tail = head;
//    }
//
//    void insert(int num, int position)
//    {
//        if (position == 0)
//            push_front(num);
//        else if (head == nullptr)
//            throw std::out_of_range("Cannot insert");
//
//        Node* current = head;
//        Node* previous = nullptr;
//
//        for (int i = 0; i < position; i++)
//        {
//            if (current != nullptr)
//            {
//                previous = current;
//                current = current->next;
//            }
//            else
//                throw std::out_of_range("Cannot insert");
//        }
//
//        previous->next = new Node(num, current);
//
//        if (tail == previous)
//            tail = previous->next;
//    }
//
//    void print() const
//    {
//        Node* current = head;
//
//        while (current != nullptr)
//        {
//            std::cout << current->data << " ";
//            current = current->next;
//        }
//
//        std::cout << '\n';
//    }
//};
//
//int main()
//{
//    List list;
//
//    int counter;
//    std::cin >> counter;
//
//    for (int i = 0; i < counter; i++)
//    {
//        int num;
//        std::cin >> num;
//
//        list.push_back(num);
//    }
//
//    int number, position;
//    std::cin >> number;
//    std::cin >> position;
//
//    list.insert(number, position);
//
//    list.print();
//}