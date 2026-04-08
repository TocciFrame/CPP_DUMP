#include "node.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;

class List {
    public:
    virtual node* insert(node* curr, int num) = 0;
    virtual node* remove(node* curr, int num) = 0;
    virtual bool search(int num) = 0;
    virtual void print() = 0;
};