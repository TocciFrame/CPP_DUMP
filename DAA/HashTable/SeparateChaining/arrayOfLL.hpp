#include <iostream>
using namespace std;

struct node {
    int key;
    int value;
    node* next;

    node (int k, int v) {
        key = k;
        value = v;
        next = nullptr;
    }
};

class ArrayOfLL {
    int size;
    node** hash;
    
    int hashHelper(int k) {
        return k % size;
    }

    public:
    ArrayOfLL(int s) {
        size = s;
        hash = new node*[size];
        for (int i = 0; i < size; i++) {
            hash[i] = nullptr;
        }
    }

    void insert(int key, int value) {
        int i = hashHelper(key);
        node* n = new node(key, value);

        if (!hash[i]) {
            hash[i] = n;
        } else {
            node* curr = hash[i];
            while (curr->next) {
                curr = curr->next;
            }
            curr->next = n;
        }
    }

    void remove(int key) {
        int i = hashHelper(key);
        node* curr = hash[i];
        node* prev = nullptr;

        while (curr && curr->key != key) {
            prev = curr;
            curr = curr->next;
        }

        if (!curr) return;

        if (!prev) {
            hash[i] = curr->next;
        } else {
            prev->next = curr->next;
        }
        delete curr;
    }

    int search(int key) {
        int i = hashHelper(key);
        node* curr = hash[i];

        while (curr) {
            if (curr->key == key) {
                return curr->value;
            }
            curr = curr->next;
        }

        return -1;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            node* curr = hash[i];
            cout << "Index " << i << ": ";
            while (curr) {  
                cout << "(" << curr->key << ", " << curr->value << ") -> ";
                curr = curr->next;
            }
            cout << "nullptr" << endl;
        }
    }
};