#include "vertex.hpp"

struct edge {
    char name;
    vertex* origin;
    vertex* dest;
};

/* Adjacency List
struct edge {
    char name;
}
*/