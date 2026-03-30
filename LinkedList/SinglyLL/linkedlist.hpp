#include "list.hpp"
#include "node.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;

class LinkedList : public List {
    int size;
    Node *head, *tail;

    public:
    void add(int num){
        Node* new_node = (Node*)calloc(1, sizeof(Node));
        new_node->data = num;
        new_node->next = nullptr;

        if (!head) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
        size++;
    }
    void addHead(int num){
        Node* new_node = (Node*)calloc(1, sizeof(Node));
        new_node->data = num;
        if (!head) {
            new_node->next = nullptr;
            head = new_node;
            tail = new_node;
        } else {
            new_node->next = head;
            head = new_node;
        }
        size++;
    }
    void addTail(int num){
        Node* new_node = (Node*)calloc(1, sizeof(Node));
        new_node->data = num;
        new_node->next = nullptr;

        if (!head) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
        size++;
    }
    void addAt(int num, int pos){
        if (pos == 1){
            addHead(num);
            return;
        }
        if (pos > size){
            addTail(num);
            return;
        }

        Node* curr = head;
        for (int i = 1; i < pos - 1; i++){
            curr = curr->next;
        }

        Node* new_node = (Node*)calloc(1, sizeof(Node));
        new_node->data = num;
        new_node->next = curr->next; 
        curr->next = new_node;   
        size++;
    }
    int clear(){
        int count = 0;
        Node* curr = head;
        Node* next = nullptr;

        while (curr){
            next = curr->next;
            curr->next = nullptr;
            curr = next;
            count++;
        }
        head = nullptr;
        return count;
    }
    void remove(int num){
        Node* curr = head;
        Node* prev;

        while(curr){
            if (curr->data == num){
                if (curr == head){
                    head = head->next;
                    size--;
                    delete curr;
                    return;
                }else{
                    prev->next = curr->next;
                    size--;
                    delete curr;
                    return;
                }
            }
            prev = curr;
            curr = curr->next;
        }
    }
    void removeAt(int pos){
        if (pos > size) return;

        Node* curr = head;
        Node* prev;

        for (int i = 1; i < pos; i++){
            prev = curr;
            curr = curr->next;
        }
        if (curr == head){
            head = head->next;
            size--;
            return;
        }
        prev->next = curr->next;
        size--;
    }
    int removeAll(int num){
        int count = 0;
        Node* curr = head;
        Node* prev = nullptr;

        while(curr){
            if (curr->data == num){
                if (curr == head){
                    head = head->next;
                    curr = head;
                }else{
                    prev->next = curr->next;
                    curr = curr->next;
                }
                count++;
                size--;
            }else{
                prev = curr;
                curr = curr->next;
            }
        }
        return count;
    }
    void replace(int num, int pos){
        if (pos > size) return;

        Node* curr = head;
        for (int i = 1; i < pos; i++){
            curr = curr->next;
        }

        curr->data = num;
    }
    void flip(){
        Node* curr = head;
        Node* prev = nullptr;
        Node* next = nullptr;

        tail = head;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    int get(int pos){
        Node* curr = head;
        int count = 1;
        while(curr){
            count++;
            if(count == pos){
                return curr->data;
            }
            curr = curr->next;
        }
        return -1;
    }

    void print(){
        if (head == nullptr){
                cout << "The list is empty" << endl;
                return;
            }

        Node* curr = head;

        while(curr){
            cout << curr->data;
            if (curr->next != nullptr){
                cout << " -> ";
            }
            curr = curr->next;
        }
        cout << endl;
    }
};