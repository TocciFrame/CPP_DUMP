#include "list.hpp"
#include "node.hpp"
#include <iostream>
using namespace std;

class LinkedList : public List {
    int size;
    node* head;
    node* tail;

    public:
    LinkedList() {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    void add(int num) {
        node* n = new node;
        n->elem = num;
        n->next = nullptr;
        if (!head) {
            head= n;
            tail = n;
        } else {
            tail->next = n;
            tail = n;
        }
        size++;
    }

    int get(int pos) {
        node* curr = head;
        int count = 0;
        while (curr) {
            if (count < pos) {
                curr = curr->next;
                count++;
            } else {
                return curr->elem;
            }
        }
        return -1;
    }

    void swap(int pos1, int pos2) {
        if (pos1 == pos2) {
            return;
        }

        node *prev1 = nullptr, *curr1 = head;
        node *prev2 = nullptr, *curr2 = head;

        for (int i = 0; i < pos1; i++) {
            prev1 = curr1;
            curr1 = curr1->next;
        }

        for (int i = 0; i < pos2; i++) {
            prev2 = curr2;
            curr2 = curr2->next;
        }

        if (curr1 == nullptr || curr2 == nullptr) {
            return;
        }
        
        if (prev1) {
            prev1->next = curr2;
        } else {
            head = curr2;
        }

        if (prev2) {
            prev2->next = curr1;
        } else {
            head = curr1;
        }

        if (curr1->next == curr2) {
            curr1->next = curr2->next;
            curr2->next = curr1;
        } else if (curr2->next == curr1) {
            curr2->next = curr1->next;
            curr1->next = curr1;
        } else {
            node* temp = curr1->next;
            curr1->next = curr2->next;
            curr2->next = temp;
        }

        if (curr1 == tail) {
            tail = curr2;
        } else if (curr2 == tail) {
            tail = curr1;
        }
    }

    int s() {
        return size;
    }


    void print() {
        node* curr = head;

        while (curr) {
            if (curr != tail) {
                cout << curr->elem << " -> ";
            } else {
                cout << curr->elem;
            }
            curr = curr->next;
        }
        cout << endl;
    }
};