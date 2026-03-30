#include <iostream>
using namespace std;

struct node {
    int key;
    int value;

    node(int k, int v) {
        key = k;
        value = v;
    }
};

class LinearProbing {
    node** hash;
    int size, capacity;
    node* deleted;

    int hashHelper(int k) {
        return k % capacity;
    }

    public:
    LinearProbing(int c) {
        capacity = c;
        size = 0;
        hash = new node*[capacity];
        for (int i = 0; i < capacity; i++) {
            hash[i] = nullptr;
        }
        deleted = new node(-1, -1);
    }

    void insert(int key, int value) {
        int i = hashHelper(key);
        while (hash[i] && hash[i] != deleted && hash[i]->key != key) {
            i = (i + 1) % capacity;
        }

        if (!hash[i] || hash[i] == deleted) {
            if (hash[i] == deleted) {
                delete hash[i];
            }
            hash[i] = new node(key, value);
            size++;
        } else {
            hash[i]->value = value;
        }
    }

    bool remove(int key) {
        int i = hashHelper(key);
        int start = i;

        while (hash[i]) {
            if (hash[i] != deleted && hash[i]->key == key) {
                delete hash[i];

                int next = (i + 1) % capacity;
                if (hash[next] == nullptr) {
                    hash[i] = nullptr;

                    int prev = (i - 1 + capacity) % capacity;
                    while (hash[prev] == deleted) {
                        hash[prev] = nullptr;
                        prev = (prev - 1 + capacity) % capacity;
                    }

                } else {
                    hash[i] = deleted;
                }
                size--;
                return true;
            }
            i = (i + 1) % capacity;
            if (i == start) break;
        }
        return false;
    }

    int get(int key) {
        int i = hashHelper(key);
        int start = i;

        while (hash[i]) {
            if (hash[i] != deleted && hash[i]->key == key) {
                return hash[i]->value;
            }
            i = (i + 1) % capacity;
            if (i == start) break;
        }
        return -1;
    }

    bool search(int key) {
        return get(key) != -1;
    }

    void print() {
        for (int i = 0; i < capacity; i++) {
            cout << i << ": ";

            if (!hash[i]) {
                cout << "null" << endl;
            } else if (hash[i] == deleted) {
                cout << "-1" << endl;
            } else {
                cout << hash[i]->key << endl;
            }
        }
        cout << endl;
    }
};