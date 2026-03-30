#include <iostream>
#include "arrayOfLL.hpp"
using namespace std;

int main() {
    ArrayOfLL* a = new ArrayOfLL(7);

    a->insert(90, 1);
    a->insert(4, 2);
    a->insert(13, 3);
    a->insert(11, 4);
    a->insert(18, 5);
    a->print();

    cout << endl;

    a->remove(11);
    a->print();

    cout << a->search(18) << endl;
}