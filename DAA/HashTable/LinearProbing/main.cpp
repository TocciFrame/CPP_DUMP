#include <iostream>
#include "hashTable.hpp"
using namespace std;

int main() {
    int N;
    cout << "How many elements do you want to insert? ";
    cin >> N;

    HashTable<int>* ht = new HashTable<int>(N);
    char op;

    do {
        cout << "Operation: ";
        cin >> op;
        switch (op) {
            int k;
            case 'i':
                cin >> k;
                cout << ht->insert(k) << endl;
                break;
            case 'r':
                cin >> k;
                cout << ht->remove(k) << endl;;
                break;
            case 's':
                cin >> k;
                cout << ht->search(k) << endl;
                break;
            case 'p':
                ht->print();
                break;
            case 'x':
                break;
        }
    } while (op != 'x');
    return 0;   
}