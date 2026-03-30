#pragma once

class List {
    public:
    virtual void add(int) = 0;
    virtual void print() = 0;
    virtual int get(int) = 0;
    virtual int s() = 0;
    virtual void swap(int, int) = 0;
};