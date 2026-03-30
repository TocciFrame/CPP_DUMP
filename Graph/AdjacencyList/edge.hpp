#include <cstdlib>
#include <iostream>
using namespace std;

class Edge {
    private:
    int name;
    char origin;
    char destination;

    public:
    // ADD more methods as necessary
    Edge(char u, char v, char x) {
        name = x;
        origin = u;
        destination = v;
    }
    
    int getName() {
        return name;
    }
    char getOrig() {
        return origin;
    }
    char getDest() {
        return destination;
    }

    void toString() {
        cout << name << " | (" << origin << " -> " << destination << ")";
    }
};