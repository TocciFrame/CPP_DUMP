#include <iostream>
#include <algorithm>
using namespace std;

int knapsack(int* value, int* weight, int n, int W, int** memo) {
    if (n == 0 || W == 0) return 0;
    if (memo[n][W] != -1) memo[n][W];
    
    if (weight[n - 1] > W) {
        memo[n][W] = knapsack(value, weight, n - 1, W, memo);
        return memo[n][W];
    }
    
    return memo[n][W] = max(
        value[n - 1] + knapsack(value, weight, n - 1, W - weight[n - 1], memo),
        knapsack(value, weight, n - 1, W, memo));
}

int main() {
    int n, W;
    
    cout << "Enter number of items and weight capacity: ";
    cin >> n >> W;
    
    cout << "Enter value and weight of each item:" << endl;
    
    int value[n];
    int weight[n];
    
    for (int i = 0; i < n; i++) {
        cin >> value[i] >> weight[i];
    }
    
    int** memo = (int**) calloc (n + 1, sizeof(int*));
    
    for (int i = 0; i <= n; i++) {
        memo[i] = (int*) calloc (W + 1, sizeof(int));
        for (int j = 0 ; j <= W; j++) {
            memo[i][j] = -1;
        }
    }
    int maxVal = knapsack(value, weight, n, W, memo);
    
    cout << "Maximum value in Knapsack = " << maxVal << endl;
    return 0;
}