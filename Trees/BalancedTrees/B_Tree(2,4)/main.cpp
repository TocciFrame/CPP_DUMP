#include "btree.hpp"
#include <iostream>
using namespace std;
int main() {
    BTree* tree = new BTree();

    char op;
    int num;
    do {
        cout << "Operation: ";
        cin >> op;
        switch (op) {
            case 'i':
                cin >> num;
                tree->insert(num);
                break;
            case 'r':
                cin >> num;
                cout << (tree->remove(num) ? "Removed" : to_string(num) + " not found") << endl;
                break;
            case 'p':
                tree->print();
                break;
            case 'x':
                cout << "Exiting";
                break;
            default:
                cout << "Invalid operation";
        }
    } while (op != 'x');
    return 0;
};