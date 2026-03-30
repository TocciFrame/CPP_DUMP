#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

// Using Push and Pop
bool isValid(string& s){
    stack<char> st;

    for (char c : s){
        if (c == '(' || c == '[' || c == '{'){
            st.push(c);
        }else if (c == ')' || c == ']' || c == '}'){
            if (st.empty()) return false;

            if (c == '(' && st.top() != ')' || c == '[' && st.top() != ']' || c == '{' && st.top() != '}') {
                return false;
            }

            st.pop();
        }
    }

    return st.empty();
}
int main(){
    string s;
    cout << "Enter a string of parentheses: ";
    cin >> s;

    if (isValid(s)){
        cout << "True" << endl;
    }else {
        cout << "False" << endl;
    }
    return 0;
}