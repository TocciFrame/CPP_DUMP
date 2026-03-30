#include "node.hpp"
#include <iostream>
using namespace std;

class GenTree {
    public:
    virtual node* addRoot(int) = 0;
    virtual node* addLeft(node*, int) = 0;
    virtual node* addRight(node*, int) = 0;
    virtual void remove(node*) = 0;
    virtual int getRoot() = 0;
    virtual int size() = 0;
    virtual void print() = 0;
};
