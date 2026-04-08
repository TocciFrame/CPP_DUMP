#include <iostream>
#include "avl.hpp"

int main() {
    AVL* avl = new AVL();
    int num;
    char op;
    do {
        cout << "Op: ";
        cin >> op;
        switch (op) {
            case 'i': 
                cin >> num;
                avl->insert(num);
                break;
            case 's':
                cin >> num;
                cout << "Is there " << num << "? " << avl->search(num) << endl;
                break;
            case 'r':
                cin >> num;
                avl->remove(num);
                break;
            case 'p':
                avl->print();
                break;
            case 'x':
                cout << "Exiting" << endl;
                break;
            default:
                cout << "Invalid operation" << endl;
        }
    } while (op != 'x');

    return 0;
}