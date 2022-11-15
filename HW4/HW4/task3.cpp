//#include <bits/stdc++.h>
//
//using namespace std;
//
//string ltrim(const string&);
//string rtrim(const string&);
//
//class SinglyLinkedListNode {
//public:
//    int data;
//    SinglyLinkedListNode* next;
//
//    SinglyLinkedListNode(int node_data) {
//        this->data = node_data;
//        this->next = nullptr;
//    }
//};
//
//class SinglyLinkedList {
//public:
//    SinglyLinkedListNode* head;
//    SinglyLinkedListNode* tail;
//
//    SinglyLinkedList() {
//        this->head = nullptr;
//        this->tail = nullptr;
//    }
//
//    void insert_node(int node_data) {
//        SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);
//
//        if (!this->head) {
//            this->head = node;
//        }
//        else {
//            this->tail->next = node;
//        }
//
//        this->tail = node;
//    }
//};
//
//void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
//    while (node) {
//        fout << node->data;
//
//        node = node->next;
//
//        if (node) {
//            fout << sep;
//        }
//    }
//}
//
//SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position)
//{
//    if (position == 0)
//    {
//        SinglyLinkedListNode* temp;
//        temp = llist;
//
//        if (llist != nullptr)
//        {
//            llist = llist->next;
//            delete temp;
//        }
//
//        return llist;
//    }
//
//    SinglyLinkedListNode* current;
//    SinglyLinkedListNode* previous;
//
//    current = llist;
//    previous = nullptr;
//
//    for (int i = 0; i < position; i++)
//    {
//        if (current != nullptr)
//        {
//            previous = current;
//            current = current->next;
//        }
//        else
//            throw std::out_of_range("Cannot remove");
//    }
//
//    previous->next = current->next;
//
//    delete current;
//
//    return llist;
//}
//
//int main()
//{
//    ofstream fout(getenv("OUTPUT_PATH"));
//
//    SinglyLinkedList* llist = new SinglyLinkedList();
//
//    string llist_count_temp;
//    getline(cin, llist_count_temp);
//
//    int llist_count = stoi(ltrim(rtrim(llist_count_temp)));
//
//    for (int i = 0; i < llist_count; i++) {
//        string llist_item_temp;
//        getline(cin, llist_item_temp);
//
//        int llist_item = stoi(ltrim(rtrim(llist_item_temp)));
//
//        llist->insert_node(llist_item);
//    }
//
//    string position_temp;
//    getline(cin, position_temp);
//
//    int position = stoi(ltrim(rtrim(position_temp)));
//
//    SinglyLinkedListNode* llist1 = deleteNode(llist->head, position);
//
//    print_singly_linked_list(llist1, " ", fout);
//    fout << "\n";
//
//    fout.close();
//
//    return 0;
//}
//
//string ltrim(const string& str) {
//    string s(str);
//
//    s.erase(
//        s.begin(),
//        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
//    );
//
//    return s;
//}
//
//string rtrim(const string& str) {
//    string s(str);
//
//    s.erase(
//        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
//        s.end()
//    );
//
//    return s;
//}
