#include <iostream>
using namespace std;

int longestIncreasingSubsequence(int arr[], int n) {
    int dp[n];
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    int maxLength = 0;
    for (int i = 0; i < n; i++) {
        maxLength = max(maxLength, dp[i]);
    }
    
    return maxLength;
}

int main() {
    int n;
    cout << "Enter the size: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = longestIncreasingSubsequence(arr, n);
    cout << "Length of the longest increasing subsequence: " << result << endl;
    return 0;
}