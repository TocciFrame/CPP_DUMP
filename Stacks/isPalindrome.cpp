#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    string str;
    cout << "Enter a string: ";
    cin >> str;

    stack<char> stk;

    for (int i = 0; i < str.size(); i++){
        stk.push(str[i]);
    }

    stack<char> stk2;

    for (int i = 0; i < str.size() / 2; i++){
        stk2.push(stk.top());
        stk.pop();
    }

    if (stk.size() > stk2.size()){
        stk.pop();
    }

    while(!stk.empty() && !stk.empty()){
        if (stk.top() != stk2.top()){
            cout << str << " is not a Palindrome" << endl;
            return 0;
        }

        stk.pop();
        stk2.pop();
    }

    cout << str << " is a Palindrome" << endl;

    return 0;
}