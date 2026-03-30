#include "list.hpp"
#include "node.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;

class LinkedList : public List {
    int size;
    Node *head, *tail;

    public:
    void addTail(int num){
        Node* newNode = (Node*)calloc(1, sizeof(Node));
        newNode->data = num;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        
        if (tail){
            tail-> next = newNode;
            newNode->prev = tail;   
        }else{
            head = newNode;
        }
        tail = newNode;
        size++;
    }
    void addHead(int num){
        Node* newNode = (Node*)calloc(1, sizeof(Node));
        newNode->data = num;
        newNode->next = head;
        newNode->prev = nullptr;

        if (head){
            head->prev = newNode;
        }else{
            tail = newNode;
        }
        head = newNode;
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

        Node* newNode = (Node*)calloc(1, sizeof(Node));
        newNode->data = num;
        newNode->next = curr->next;
        newNode->prev = curr;
        curr->next->prev = newNode;
        curr->next = newNode;
        size++;
    }
    int removeHead(){
        if (!head){
            cout << "The list is empty" << endl;
            return 0;
        }

        Node* temp = head;
        int val = head->data;
        head = head->next;
        if (head){
            head->prev = NULL;
        }
        delete temp;
        size--;
        return val;
    }
    int removeTail(){
        if(!tail){
            cout << "The list is empty" << endl;
            return 0;
        }

        Node* temp = tail;
        int val = tail->data;
        tail = tail->prev;
        if (tail){
            tail->next = NULL;
        }

        delete temp;
        size--;
        return val;
    }
    int remove(int num){
        Node* curr = head;

        while(curr){
            if(curr->data == num){
                int val = curr->data;

                if(curr->prev == NULL){
                    head = curr->next;
                    if(head){
                        head->prev = NULL;
                    }
                }else if(curr->next == NULL){
                    curr->prev->next = NULL;
                }else{
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                }
                delete curr;
                size--;
                return val;
            }
            curr = curr->next;
        }
        return -1;
    }
    void flip(){
        Node* curr = head;
        Node* temp = NULL;

        while(curr){
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }
        if (temp){
            head = temp->prev;
        }

    }
    int get(int pos){
        Node* curr = head;
        int index = 0;

        while(curr){
            index++;
            if (index == pos){
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