#include "linkedlist.hpp"
#include <iostream>
using namespace std;

int main() {
    List* list = new LinkedList();
    char op;
    int num, pos;
    int choice;

    do {
        cout << "Operator: ";
        cin >> op;
        switch(op){
            case 'A':
                cin >> num;
                list->add(num);
                cout << "Added value/s to the list." << endl;
                break;
            case 'H':
                cin >> num;
                list->addHead(num);
                cout << "Added a value to the head of the list." << endl;
                break;
            case 'T':
                cin >> num;
                list->addTail(num);
                cout << "Added a value to the tail of the list." << endl;
                break;
            case '@':
                cin >> num;
                cin >> pos;
                list->addAt(num, pos);
                cout << "Added a value to position " << pos << " in the list." << endl;
                break;
            case 'R':
                cin >> choice;
                switch(choice){
                    case 0:
                        cout << "Cleared " << list->clear() << " value/s in the list" << endl;
                        break;
                    case 1:
                        cin >> num;
                        list->remove(num);
                        cout << "Removed '" << num << "' from the list." << endl;
                        break;
                    case 2:
                        cin >> pos;
                        list->removeAt(pos);
                        cout << "Removed value at position " << pos << " from the list." << endl;
                        break;
                    case 3:
                        cin >> num;
                        cout << "Removed " << list->removeAll(num) << " occurrences of '" << num << "' from the list." << endl;
                        break;
                    case 4:
                        cin >> pos;
                        cin >> num;
                        list->replace(num, pos);
                        cout << "Replaced value at position " << pos << " with value of " << num << endl;
                        break;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                }
                break;
            case 'F':
                list->flip();
                cout << "Flipped the list." << endl;
                break;
            case 'G':
                cin >> pos;
                cout << "Value at index " << pos << ": " << list->get(pos) << endl;
                break;
            case 'P':
                list->print();
                break;
            case 'X':
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid operation. Please try again." << endl;
        }
    }while(op != 'X');
    return 0;
}