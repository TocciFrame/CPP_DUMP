#include "node.hpp"

class GenTree {
    public:
    virtual node* addRoot(int) = 0;
    virtual node* addLeft(node*, int) = 0;
    virtual node* addRight(node*, int) = 0;
    virtual void remove(node*) = 0;
};