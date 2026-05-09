#include <iostream>
#include <climits>
using namespace std;

int firstMin(int i, int n, int** adj) {
    int m = INT_MAX;
    for (int k = 0; k < n; k++) {
        if (adj[i][k] < m && i != k) {
            m = adj[i][k];
        }
    }
    return m;
}

int secondMin(int i, int n, int** adj) {
    int first = INT_MAX;
    int second = INT_MAX;
    
    for (int j = 0; j < n; j++) {
        if (i == j) continue;
        if (adj[i][j] <= first) {
            second = first;
            first = adj[i][j];
        } else if (adj[i][j] <= second) {
            second = adj[i][j];
        }
    }
    
    return second;
}

void tsp(int bound, int w, int level, int idx, int n, int** adj, bool* visited, int& min_cost) {
    if (level == n) {
        int start = adj[idx][0];
        int total_w =  w + start;
        
        if (total_w < min_cost) min_cost = total_w;
        return;
    }
    
    for (int i = 0; i < n; i++) {
        if (i != idx && !visited[i]) {
            int temp = bound;
            int edge = adj[idx][i];
            
            if (level == 1) {
                bound -= ((firstMin(idx, n, adj) + firstMin(i, n, adj)) / 2);
            } else {
                bound -= ((secondMin(idx, n, adj) + secondMin(i, n, adj)) / 2);
            }
            
            if (w + edge + bound < min_cost) {
                visited[i] = true;
                
                tsp(bound, w + edge, level + 1, i, n, adj, visited, min_cost);
                visited[i] = false;
            }
            bound = temp;
        }
    }
}

int main() {
    int n;
    cout << "Enter number of cities: ";
    cin >> n;
    
    int** graph = new int*[n];
    
    for (int i = 0; i < n; i++) {
        graph[i] = new int[n];
    }
    
    cout << "Enter adjacency matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    
    int min_cost = INT_MAX;
    int bound = 0;
    
    for (int i = 0; i < n; i++) {
        bound += (firstMin(i, n, graph) + secondMin(i, n, graph));
    }
    
    bound = (bound + 1) / 2;
    
    visited[0] = true;
    tsp(bound, 0, 1, 0, n, graph, visited, min_cost);
    
    cout << "Minimum cost: " << min_cost << endl;
    
    return 0;
}