//#include <cmath>
//#include <cstdio>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//struct Node {
//    int value;
//    Node* previous;
//    Node* next;
//
//    Node(int value) {
//        this->value = value;
//        previous = nullptr;
//        next = nullptr;
//    }
//
//    Node(int value, Node* next, Node* previous) {
//        this->value = value;
//        this->next = next;
//        this->previous = previous;
//    }
//};
//
//Node* arr[1000000]{ 0 };
//
//class List
//{
//private:
//    Node* head;
//    Node* tail;
//    int count = 0;
//
//public:
//    List()
//    {
//        head = nullptr;
//        tail = nullptr;
//    }
//
//    void push_front(Node* current) {
//        count++;
//
//        if (head == nullptr) {
//            head = current;
//            tail = head;
//            return;
//        }
//
//        current->next = head;
//        head->previous = current;
//        head = current;
//    }
//
//    int getCount() const
//    {
//        return count;
//    }
//
//    Node* peek_front() {
//        return head;
//    }
//
//    void change(int num)
//    {
//        Node* current = arr[num];
//        Node* previous = current->previous;
//        Node* next = current->next;
//
//        if (tail == current && tail != head)
//            tail = tail->previous;
//
//        if (previous != nullptr)
//            previous->next = next;
//
//        if (next != nullptr && current != head)
//            next->previous = previous;
//
//        if (current != head)
//        {
//            current->next = head;
//            current->previous = nullptr;
//
//            head->previous = current;
//            head = current;
//        }
//    }
//
//    void add(int num)
//    {
//        Node* newNode = new Node(num);
//        newNode->next = head;
//
//        head->previous = newNode;
//
//        Node* previous = tail->previous;
//
//        arr[tail->value] = nullptr;
//        tail = previous;
//
//        previous->next = nullptr;
//
//        arr[num] = newNode;
//
//        head = newNode;
//    }
//
//};
//
//int main()
//{
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//
//    int T, N;
//    std::cin >> T >> N;
//
//    List list;
//
//    if (N == 1)
//    {
//        int previous = 0;
//        for (int i = 0; i < T; i++)
//        {
//            int num;
//            std::cin >> num;
//
//            if (i == 0)
//            {
//                std::cout << "false" << '\n';
//                previous = num;
//            }
//            else
//            {
//                if (num == previous)
//                {
//                    std::cout << "true" << '\n';
//                }
//                else
//                {
//                    std::cout << "false" << '\n';
//                }
//
//                previous = num;
//            }
//        }
//    }
//    else
//    {
//        int packages = 0;
//
//        for (int i = 0; i < T; i++)
//        {
//            int num;
//            std::cin >> num;
//
//            Node* current = new Node(num);
//
//            if (list.getCount() == 0)
//            {
//                std::cout << "false" << '\n';
//
//                list.push_front(current);
//
//                arr[num] = current;
//
//                packages++;
//            }
//            else
//            {
//                if (arr[num] != nullptr)
//                {
//                    std::cout << "true" << '\n';
//                    list.change(num);
//                }
//                else if (packages < N)
//                {
//                    std::cout << "false" << '\n';
//
//                    arr[num] = current;
//
//                    packages++;
//
//                    list.push_front(current);
//                }
//                else
//                {
//                    std::cout << "false" << '\n';
//                    list.add(num);
//                }
//            }
//        }
//    }
//}