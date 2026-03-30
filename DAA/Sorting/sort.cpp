#include <iostream>
#include "array.hpp"
#include "linkedlist.hpp"
using namespace std;

void bubbleSort(List* list) {
    int size = list->s();

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (list->get(j) > list->get(j + 1)) {
                list->swap(j, j + 1);
                list->print();
            }
        }
    }
}

void selectionSort(List* list) {
    int size = list->s();
    
    for (int i = 0; i < size - 1; i++) {
        int smallest = i;
        for (int j = i + 1; j < size; j++) {
            if (list->get(j) < list->get(smallest)) {
                smallest = j;
            }
        }

        if (smallest != i) {
            list->swap(i, smallest);
            list->print();
        }
    }
}

void insertionSort(List* list) {
    int size = list->s();

    for (int i = 1; i < size; i++) {
        for (int j = i; j >= 0 && list->get(j) < list->get(j - 1); j--) {
            list->swap(j, j - 1);
            list->print();
        }
    }
}

int main() {
    List* array = new Array();
    List* ll = new LinkedList();

    // array->add(3);
    // array->add(1);
    // array->add(5);
    // array->add(2);
    // array->add(4);
    // array->print();

    ll->add(40);
    ll->add(8);
    ll->add(8);
    ll->add(3);
    ll->add(28);
    ll->print();

    cout << endl;

    // cout << "Bubble Sort: " << endl;
    // cout << "Array: " << endl;
    // bubbleSort(array);

    // cout << "LL: " << endl;
    // bubbleSort(ll);
    // cout << endl;

    // cout << "Selection Sort: " << endl;
    // cout << "Array: " << endl;
    // selectionSort(array);

    // cout << "LL: " << endl;
    // selectionSort(ll);
    // cout << endl;

    // cout << "Insertion Sort: " << endl;
    // cout << "Array: " << endl;
    // insertionSort(array);

    // cout << "LL: " << endl;
    // insertionSort(ll);
    // cout << endl;

    return 0;
}