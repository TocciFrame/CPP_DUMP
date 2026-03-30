#include <iostream>
using namespace std;

long long* arr;

long long helper(int n) {
    if (n <= 1) {
        return n;
    }

    if (arr[n] != -1) {
        return arr[n];
    }

    arr[n] = helper(n - 1) + helper(n - 2);

    return arr[n];
}

long long fib(int n) {
    arr = new long long[n + 1];

    for (int i = 0; i <= n; i++) {
        arr[i] = -1;
    }
    return helper(n);
}

int main() {
    cout << fib(100) << endl;
    
    return 0;
}