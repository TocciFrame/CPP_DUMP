#include "circularLL.hpp"
#include <iostream>
using namespace std;

int main(){
    CircularLinkedList* list = new LinkedList();
    char op;
    int num, pos;
    int choice;

    do {
        cout << "Operator: ";
        cin >> op;
        switch(op){
            case 'H':
                cin >> num;
                list->insertHead(num);
                cout << "Inserted " << num << " to the list." << endl;
                break;
            case 'A':
                cin >> num >> pos;
                list->insertAt(num, pos);
                cout << "Inserted " << num << " at position " << pos << "." << endl;
                break;
            case 'T':
                cin >> num;
                list->insertTail(num);
                cout << "Inserted " << num << " to the list." << endl;
                break;
            case 'R':
                cout << "Enter choice (0: delete list, 1: delete head, 2: delete tail, 3: delete at position, 4: delete one value, 5: delete all value): ";
                cin >> choice;
                switch(choice){
                    case 1:
                        cout << "Deleting head..." << endl;
                        list->deleteHead();
                        break;
                    case 2:
                        cout << "Deleting tail..." << endl;
                        list->deleteTail();
                        break;
                    default:
                        cout << "Invalid choice." << endl;
                        break;
                }
                break;
            case 'r':
                cout << "The list rotated." << endl;
                list->rotate();
                break;
            case 'G':
                cin >> pos;
                cout << "Value at position " << pos << " is " << list->get(pos) << endl;
                break;
            case 'D':
                list->display();
                break;
            case 'X':
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid operator." << endl;
                break;
        }
    } while (op != 'X');

    delete list;
    return 0;
}