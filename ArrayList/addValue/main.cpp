#include "arraylist.hpp"
#include <iostream>
using namespace std;

int main() {
    List* list = new ArrayList();
    char op;
    int num, pos;
    int choice;

    cout << "Add(A); AddAt(a); Remove(R); Flip(F); Plus(+); Summation(S); Get(G); Print(P); Exit(X)" << endl;
    cout << "======================================================================================" << endl;

    do {
        cout << "Operator: ";
        cin >> op;
        switch(op){
            case 'A':
                // cout << "Enter number to add: ";
                // cin >> num;
                // list->add(num);

                list->add(10);
                list->add(20);
                list->add(30);
                list->add(40);
                list->add(50);
                cout << "Added value/s to the list." << endl;
                break;
            case 'a':
                cout << "Enter position to add: ";
                cin >> pos;
                cout << "Enter number to add: ";
                cin >> num;
                list->addAt(pos, num);
                cout << "Added a value to position " << pos << " in the list." << endl;
                break;
            case 'R':
                cout << "Enter choice (1: Remove; 2: RemoveAt; 3: RemoveAll): ";
                cin >> choice;
                switch(choice){
                    case 1:
                        cout << "Enter value to remove: ";
                        cin >> num;
                        list->remove(num);
                        cout << "Removed '" << num << "' from the list." << endl;
                        break;
                    case 2:
                        cout << "Enter position to remove: ";
                        cin >> pos;
                        list->removeAt(pos);
                        cout << "Removed value at position " << pos << " from the list." << endl;
                        break;
                    case 3:
                        cout << "Enter value to remove all occurrences: ";
                        cin >> num;
                        cout << "Removed " << list->removeAll(num) << " occurrences of '" << num << "' from the list." << endl;
                        break;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                }
                break;
            case 'F':
                list->flip();
                cout << "Flipped the list." << endl;
                break;
            case '+':
                int term;
                cout << "Enter term to add: ";
                cin >> term;
                list->plus(term);
                cout << "Added " << term << " to all elements in the list." << endl;
                break;
            case 'S':
                cout << "The summation of all element in the list is " << list->summation() << endl;
                break;
            case 'G':
                cout << "Enter position to get: ";
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

    

    delete list;
    return 0;
}