#include "edge.hpp"
#include <list>

struct vertex {
    char name;
    list<Edge> out;
    list<Edge> in;
};