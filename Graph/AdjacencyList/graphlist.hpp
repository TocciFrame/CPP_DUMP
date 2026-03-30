#include <cstdlib>
#include <iostream>
#include "graph.hpp"
#include "edge.hpp"
using namespace std;

class GraphList : public Graph {
    Edge** s_edges;
    int num_edge;
    char s_vertices[10];
    int num_vert;
    
    int getVertInd(char x) {
        for (int i = 0; i < num_vert; i++) {
            if (s_vertices[i] == x) {
                return i;
            }
        }
        return -1;
    }

    public:
    GraphList() {
        s_edges = (Edge**) malloc( 100 * sizeof(Edge*) );
        num_vert = 0;
        num_edge = 0;
    }

    int numVertices() {
        return num_vert;
    }

    char* vertices() {
        return s_vertices;
    }

    int numEdges() {
        return num_edge;
    }

    int* edges() {
        int* edge = (int*)malloc(100 * sizeof(int));
        for (int i = 0; i < num_edge; i++) {
            edge[i] = s_edges[i]->getName();
        }
        return edge;
    }

    int getEdge(char u, char v)  {
        for (int i = 0; i < num_edge; i++) {
            if (s_edges[i]->getOrig() == u && s_edges[i]->getDest() == v) {
                return s_edges[i]->getName();
            }
        }
        
        return 0;
    }

    char* endVertices(int e)  {
        char* vert = (char*)malloc(2 * sizeof(char));
        
        for (int i = 0; i < num_edge; i++) {
            if (s_edges[i]->getName() == e) {
                vert[0] = s_edges[i]->getOrig();
                vert[1] = s_edges[i]->getDest();
                return vert;
            }
        }
        
        vert[0] = '-';
        vert[1] = '-';
        return vert;
    }

    char opposite(char v, int e)  {
        for (int i = 0; i < num_edge; i++) {
            if (s_edges[i]->getName() == e) {
                if (s_edges[i]->getOrig() == v) {
                    return s_edges[i]->getDest();
                }
                if (s_edges[i]->getDest() == v) {
                    return s_edges[i]->getOrig();
                }
            }
        }
        
        return '-';
    }

    int outDegree(char v)  {
        int ctr = 0;
        
        for (int i = 0; i < num_edge; i++) {
            if (s_edges[i]->getOrig() == v) {
                ctr++;
            }
        }
        
        return ctr;
    }

    int inDegree(char v)  {
        int ctr = 0;
        
        for (int i = 0; i < num_edge; i++) {
            if (s_edges[i]->getDest() == v) {
                ctr++;
            }
        }
        
        return ctr;
    }

    int* outgoingEdges(char v) {
        int deg = outDegree(v);
        int* edges = (int*)malloc(deg * sizeof(int));
        
        int ind = 0;
        for (int i = 0; i < num_edge; i++) {
            if (s_edges[i]->getOrig() == v) {
                edges[ind++] = s_edges[i]->getName();
            }
        }
        
        return edges;
    }

    int* incomingEdges(char v) {
        int deg = inDegree(v);
        int* edges = (int*)malloc(deg * sizeof(int));
        
        int ind = 0;
        for (int i = 0; i < num_edge; i++) {
            if (s_edges[i]->getDest() == v) {
                edges[ind++] = s_edges[i]->getName();
            }
        }
        
        return edges;
    }

    bool insertVertex(char x)  {
        if (num_vert >= 10) return false;
        s_vertices[num_vert++] = x;
        return true;
    }

    bool insertEdge(char u, char v, int x)  {
        if (getVertInd(u) == -1 || getVertInd(v) == -1) {
            return false;
        }
        
        s_edges[num_edge++] = new Edge(u,v,x);
        
        return true;
    }

    int removeVertex(char v) {
        int ind = getVertInd(v);
        int sum = 0;
        sum += inDegree(v);
        sum += outDegree(v);
        
        for (int i = num_edge - 1; i >= 0; i--) {
            if (s_edges[i]->getOrig() == v || s_edges[i]->getDest() == v){
                for (int j = i; j < num_edge - 1; j++) {
                    s_edges[j] = s_edges[j + 1];
                }
                num_edge--;
            }
        }
        
        for (int i = ind; i < num_vert - 1; i++) {
            s_vertices[i] = s_vertices[i + 1];
        }
        num_vert--;
        
        return sum;
    }

    bool removeEdge(int e)  {
        for (int i = 0; i < num_edge; i++) {
            if (s_edges[i]->getName() == e) {
                for (int j = i; j < num_edge - 1; j++) {
                    s_edges[j] = s_edges[j + 1];
                }
                num_edge--;
                return true;
            }
        }
        return false;
    }

    void print() {
        cout << "Vertices: ";
        for (int i = 0; i < num_vert; i++) {
            cout << s_vertices[i] << " ";
        }
        cout << endl << "Edges: " << endl;
        for (int i = 0; i < num_edge; i++) {
            s_edges[i]->toString();
            cout << endl;
        }
    }
};