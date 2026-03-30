#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int main(){
    stack<int> opStack;
    int n;

    cout << "Enter a number: ";
    cin >> n;

    string str[n];

    cout << "Enter a string: ";
    for (int i = 0; i < n; i++){
        cin >> str[i];
    }

    for (int i = n - 1; i >= 0; i--){
        if (isdigit(str[i][0])){
            opStack.push(stoi(str[i]));
        }

        if (str[i][0] == '+' || str[i][0] == '-' || str[i][0] == '*' || str[i][0] == '/'){
            char op1 = opStack.top();
            opStack.pop();
            char op2 = opStack.top();
            opStack.pop();

            switch (str[i][0]){
                case '+':
                    opStack.push(op1 + op2);
                    break;
                case '-':
                    opStack.push(op1 - op2);
                    break;
                case '*':
                    opStack.push(op1 * op2);
                    break;
                case '/':
                    if (op2 != 0){
                        opStack.push(op1 / op2);
                    } else {
                        cout << "Error: Division by zero" << endl;
                        return 1;
                    }
                    break;
                default:
                    break;
            }
        }
    }

    cout << "Result: " << opStack.top() << endl;
    return 0;
}