#include "list.hpp"
#include <iostream>
using namespace std;

class Array : public List {
    int size;
    int* arr;

    public:
    Array() {
        size = 0;
        arr = (int*)calloc(5, sizeof(int));
    }

    void add(int num) {
        arr[size++] = num;
    }

    int get(int pos) {
        return arr[pos];
    }

    int s() {
        return size;
    }

    void swap(int pos1, int pos2) {
        int temp = arr[pos1];
        arr[pos1] = arr[pos2];
        arr[pos2] = temp;
    }

    node* mergeSort(node* head) {
        return nullptr;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};