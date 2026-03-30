#include "doublyLL.hpp"
#include <iostream>
using namespace std;

int main(){
    List* list = new DoublyLL();

    list->addFirst(10);
    list->addLast(1);
    list->addLast(2);
    list->addLast(3);
    list->addLast(4);
    list->addLast(5);
    list->addAt(6, 4);
    list->print();
    
    cout << "Get element at position 1: " << list->get(1) << endl;
    cout << "Get element at position 2: " << list->get(2) << endl;
    cout << "Get element at position 3: " << list->get(3) << endl;
    cout << "Get element at position 4: " << list->get(4) << endl;
    cout << "Get element at position 5: " << list->get(5) << endl;
    cout << "Get element at position 6: " << list->get(6) << endl;

    cout << "Removed: " << list->removeFirst() << endl;
    cout << "Removed: " << list->removeLast() << endl;
    cout << "Removed: " << list->removeAt(2) << endl;
    list->print();
}