#include <cstdlib>
#include <iostream>
#include "graph.hpp"
using namespace std;

class GraphMatrix : public Graph {
    int matrix[10][10];
    char s_vertices[10];
    int num_vert;
    int s_edges[100];
    int num_edge;

    int getVertexIndex(char v) {
        for (int i = 0; i < num_vert; i++) {
            if (s_vertices[i] == v) return i;
        }
        return -1;
    }

    public:
    GraphMatrix() {
        num_vert = 0;
        num_edge = 0;

        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                matrix[i][j] = 0;
            }
        }

        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                if (matrix[i][j] == 0) {
                    cout << "";
                }
            }
        }
        
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
        return s_edges;
    }

    int getEdge(char u, char v) {
        int i1 = getVertexIndex(u), i2 = getVertexIndex(v);
        
        if (i1 == -1 || i2 == -1) {
            return 0;
        }
        return matrix[i1][i2];
    }

    char* endVertices(int e)  {
        int in = 0;
        char* v = new char[2];
        for (int i = 0; i < num_vert; ++i){
            for (int j = 0; j < num_vert; ++j){
                if (matrix[i][j] == e){
                    v[in++] = s_vertices[i];
                    v[in++] = s_vertices[j];
                    return v;
                }
            }
        }
        v[0] = '-';
        v[1] = '-';
        return v;
    }

    char opposite(char v, int e)  {
        int idx = getVertexIndex(v);
        if (idx == -1) return '-';

        for (int j = 0; j < num_vert; ++j) {
            if (matrix[idx][j] == e) return s_vertices[j];
            if (matrix[j][idx] == e) return s_vertices[j];
        }
        return '-';
    }

    int outDegree(char v)  {
        int idx = getVertexIndex(v);
        if (idx == -1) return 0;

        int deg = 0;
        for (int j = 0; j < num_vert; j++) {
            if (matrix[idx][j] != 0) deg++;
        }
        return deg;
    }

    int inDegree(char v)  {
        int idx = getVertexIndex(v);
        if (idx == -1) return 0;

        int deg = 0;
        for (int i = 0; i < num_vert; i++) {
            if (matrix[i][idx] != 0) deg++;
        }
        return deg;
    }

    int* outgoingEdges(char v) {
        int* e = new int[10 + 1]; 
        int in = 0;
        
        int idx = getVertexIndex(v);
        if (idx != -1) {
            for (int j = 0; j < num_vert; j++) {
                if (matrix[idx][j] != 0) {
                    e[in++] = matrix[idx][j];
                }
            }
        }
        e[in] = -1;
        return e;
    }

    int* incomingEdges(char v) {
        int* e = new int[10 + 1];
        int in = 0;

        int idx = getVertexIndex(v);
        if (idx != -1) {
            for (int i = 0; i < num_vert; i++) {
                if (matrix[i][idx] != 0) {
                    e[in++] = matrix[i][idx];
                }
            }
        }
        e[in] = -1;     
        return e;
    }

    bool insertVertex(char x)  {
        if (num_vert >= 10) return false; 
        s_vertices[num_vert++] = x;
        return true;
    }

    bool insertEdge(char u, char v, int x) {
        int i1 = getVertexIndex(u);
        int i2 = getVertexIndex(v);

        if (i1 == -1 || i2 == -1) return false; 
        
        matrix[i1][i2] = x;
        s_edges[num_edge++] = x;
        return true;
    }

    int removeVertex(char v) {
        int in = 0;
        for (int i = 0; i < num_vert; i++){
            if (v == s_vertices[i]) {
                in = i;
            }
        }
        
        int ctr = 0;
        for (int i = 0; i < num_vert; i++){
            if (matrix[in][i] > 0){
                removeEdge(matrix[in][i]);
                ctr++;
            }
            if (matrix[i][in] > 0){
                removeEdge(matrix[i][in]);
                ctr++;
            }
        }
        
        for (int j = 0; j < num_vert; j++){
            for (int i = in; i < num_vert - 1; i++){
                matrix[j][i] = matrix[j][i + 1];
            }
            matrix[j][num_vert - 1] = 0;
        }
        
        for (int j = 0; j < num_vert; j++){
            for (int i = in; i < num_vert - 1; i++){
                matrix[i][j] = matrix[i + 1][j];
            }
            matrix[num_vert - 1][j] = 0;
        }
        
        for (int i = in; i < num_vert - 1; i++){
            s_vertices[i] = s_vertices[i + 1];
        }
        
        num_vert--;
        
        return ctr;
    }

    bool removeEdge(int e)  {
        for (int i = 0; i < num_vert; i++){
            for (int j = 0; j < num_vert; j++){
                if (matrix[i][j] == e){
                    matrix[i][j] = 0;
                }
            }
        }
        
        int in = 0;
        
        for (int i = 0; i < num_edge; i++){
            if (e == s_edges[i]){
                in = i;
                break;
            }
        }
        for (int i = in; i < num_edge - 1; i++){
            s_edges[i] = s_edges[i + 1];
        }
        num_edge--;
        return true;
    }

    void dijkstra(char v) {
        const int INF = 1e9;
        int dist[10];
        bool visited[10] = {false};
        int startIndex = -1;

        // find starting vertex index
        for (int i = 0; i < num_vert; i++) {
            if (s_vertices[i] == v) {
                startIndex = i;
                break;
            }
        }

        // initialize distances to INF
        for (int i = 0; i < num_vert; i++) {
            dist[i] = INF;
        }

        dist[startIndex] = 0; // initialize start vertex distance to 0

        // iterate the vertices
        for (int count = 0; count < num_vert - 1; count++) {
            int minDist = INF;
            int minIndex = -1;
            
            // find smallest distance vertex not yet visited
            for (int i = 0; i < num_vert; i++) {
                if (!visited[i] && dist[i] < minDist) {
                    minDist = dist[i];
                    minIndex = i;
                }
            }

            if (minIndex == -1) break;

            visited[minIndex] = true;

            // update distances of adjacent vertices
            for (int j = 0; j < num_vert; j++) {
                if (!visited[j] && matrix[minIndex][j] != 0 &&
                    dist[minIndex] + matrix[minIndex][j] < dist[j]) {
                    dist[j] = dist[minIndex] + matrix[minIndex][j];
                }
            }
        }

        for (int i = 0; i < num_vert; i++) {
            cout << "Distance from " << v << " to " << s_vertices[i] << " is ";
            if (dist[i] == INF) {
                cout << "INF" << endl;
            } else {
                cout << dist[i] << endl;
            }
        }
    }

    void print() {
        cout << "\t";
        for (int i = 0; i < num_vert; i++) {
            cout << s_vertices[i] << "\t";
        }
        cout << endl;
        for (int i = 0; i < num_vert; i++) {
            cout << s_vertices[i] << "\t";
            for (int j = 0; j < num_vert; j++) {
                if (matrix[i][j] != 0) {
                    cout << matrix[i][j];
                }
                cout << "\t";
            }
            cout << endl;
        }
    }
};