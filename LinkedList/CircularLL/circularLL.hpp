#include "list.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;

class LinkedList : public CircularLinkedList {
    int size;

    public:
    LinkedList(){
        tail = nullptr;
        size = 0;
    }

    bool isEmpty(){
        return tail == nullptr;
    }

    void insertHead(int value){
        Node* newNode = new Node;
        newNode->data = value;
        
        if(!tail){
            newNode->next = newNode;
            tail = newNode;
        }else{
            newNode->next = tail->next;
            tail->next = newNode;
        }
        size++;
    }

    void insertAt(int value, int position){
        if (position < 0){
            return;
        }

        Node* newNode = new Node;
        newNode->data = value;

        if(position == 1){
            insertHead(value);
            return;
        }
        if (position > size){
            insertTail(value);
            return;
        }

        Node* curr = tail->next;
        for (int i = 1; i < position - 1; i++){
            curr = curr->next;
        }

        newNode->next = curr->next;
        curr->next = newNode;
        size++;
    }

    void insertTail(int value){
        Node* newNode = new Node;
        newNode->data = value;

        if (!tail){
            newNode->next = newNode;
            tail = newNode;
        }else{
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void deleteHead(){
        if (!tail){
            return;
        }

        Node* head = tail->next;
        if (head == tail){
            head = nullptr;
            delete head;
            tail = nullptr;
        }else {
            tail->next = head->next;
            head = nullptr;
            delete head;
        }
        size--;
    }

    void deleteTail(){
        if(!tail){
            return;
        }

        Node* curr = tail->next;
        while (curr->next != tail){
            curr = curr->next;
        }
        if (curr->next == tail){
            curr->next = tail->next;
            tail->next = nullptr;
            delete tail;
            tail = curr;
        }
        size--;
    }

    void rotate(){
        tail = tail->next;
    }
    
    int get(int position){
        if (position < 0 || position >= size){
            return -1;
        }

        Node* curr = tail->next;
        for (int i = 1; i < position; i++){
            curr = curr->next;
        }

        return curr->data;
    }

    void display(){
        if (!tail){
            cout << "The list is empty" << endl;
            return;
        }

        Node* curr = tail;
        do {
            rotate();
            cout << tail->data << " -> ";
        } while (tail != curr);
        cout << tail->next->data << endl;
    }

    ~LinkedList(){
        if(!tail) return;

        Node* curr = tail->next;
        while(curr != tail){
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        delete tail;
    }
};