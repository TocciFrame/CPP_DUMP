#include "node.hpp"
#include "list.hpp"
#include <iostream>
using namespace std;

class DoublyLL : public List {
    Node head, tail;
    int size;

    public:
    DoublyLL() {
        head.next = &tail;
        tail.prev = &head;
        size = 0;
    }

    Node* addBetween(int num, Node* pred, Node* succ){
        Node* newNode = new Node;
        newNode->data = num;
        newNode->next = succ;
        newNode->prev = pred;
        pred->next = newNode;
        succ->prev = newNode;
        size++;
        return newNode;
    }

    void addFirst(int num){
        addBetween(num, &head, head.next);
    }

    void addLast(int num){
        addBetween(num, tail.prev, &tail);
    }

    void addAt(int num, int pos){
        if (pos < 1 || pos > size + 1){
            cout << "Invalid position" << endl;
            return;
        }

        if (pos == 1){
            addFirst(num);
            return;
        }
        if (pos == size + 1){
            addLast(num);
            return;
        }

        if (pos <= size / 2){
            Node* curr = head.next;
            for (int i = 1; i <= pos; i++){
                curr = curr->next;
            }
            addBetween(num, curr, curr->next);
        }else {
            Node* curr = tail.prev;
            for (int i = size; i > pos; i--){
                curr = curr->prev;
            }
            addBetween(num, curr->prev, curr);
        }
    }

    int removeNode(Node* node){
        Node* pred = node->prev;
        Node* succ = node->next;
        pred->next = succ;
        succ->prev = pred;
        size--;
        int temp = node->data;
        delete node;
        return temp;
    }

    int removeFirst(){
        if (size == 0){
            cout << "List is empty" << endl;
            return -1;
        }
        return removeNode(head.next);
    }

    int removeLast(){
        if (size == 0){
            cout << "List is empty" << endl;
            return -1;
        }
        return removeNode(tail.prev);
    }

    int removeAt(int pos){
        if (pos == 1){
            return removeFirst();
        }
        if (pos == size){
            return removeLast();
        }

        if (pos <= size / 2){
            Node* curr = &head;
            for (int i = 1; i < pos; i++){
                curr = curr->next;
            }
            return removeNode(curr->next);
        }else {
            Node* curr = &tail;
            for (int i = size + 1; i > pos; i--){
                curr = curr->prev;
            }
            return removeNode(curr->prev);
        }
        return -1;
    }

    int get(int pos){
        if (pos <= size / 2){
            Node* curr = &head;
            for(int i = 1; i <= pos; i++){
                curr = curr->next;
            }
            return curr->data;
        }else{
            Node* curr = &tail;
            for(int i = size + 1; i > pos; i--){
                curr = curr->prev;
            }
            return curr->data;
        }
        return -1;
    }

    void print(){
        cout << "Size: " << size << endl;
        Node* curr = head.next;
        cout << "FROM HEAD: ";
        while(curr != &tail){
            if (curr->next != &tail){
                cout << curr->data << " -> ";
            }else{
                cout << curr->data;
            }
            curr = curr->next;
        }
        cout << endl;

        cout << "FROM TAIL: ";
        curr = tail.prev;
        while(curr != &head){
            if (curr->prev != &head){
                cout << curr->data << " -> ";
            }else{
                cout << curr->data;
            }
            curr = curr->prev;
        }
        cout << endl;
    }
};