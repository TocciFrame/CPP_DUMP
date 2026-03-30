#include "node.hpp"

class CircularLinkedList {
    protected:
    Node* tail;

    public:
    virtual void insertHead(int value) = 0;
    virtual void insertAt(int value, int position) = 0;
    virtual void insertTail(int value) = 0;

    virtual void deleteHead() = 0;
    virtual void deleteTail() = 0;

    virtual void rotate() = 0;
    virtual int get(int position) = 0;
    virtual void display() = 0;
};