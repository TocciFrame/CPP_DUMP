#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n;
    
    cout << "Enter number of elements: ";
    cin >> n;
    
    int* arr = new int[n];
    cout << "Enter preorder: ";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    long lower = -2000000000;
    stack<int> s;
    bool is_valid = true;
    
    for (int i = 0; i < n; i++){
        int curr = arr[i];
        
        if (curr < lower){
            is_valid = false;
            break;
        }
        
        while(!s.empty() && curr > s.top()){
            lower = s.top();
            s.pop();
        }
        
        s.push(curr);
    }
    
    if (is_valid){
        cout << "VALID";
    } else {
        cout << "INVALID";
    }
    
    return 0;
}