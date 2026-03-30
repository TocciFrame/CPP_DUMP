#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

int main(){
    
    stack<int> stackCount;
    stack<string> strstack;
    string curr = "";
    int num = 0;
    
    string encodedString;
    cout << "Enter encoded string: ";
    cin >> encodedString;
    
    for (char c : encodedString){
        if (isdigit(c)){
            num = c - '0';
        }else if (c == '['){
            stackCount.push(num);
            num = 0;
            
            strstack.push(curr);
            curr = "";
        }else if (c == ']'){
            int ctr = stackCount.top();
            stackCount.pop();
            
            string repeat = "";
            for (int i = 0; i< ctr; i++){
                repeat += curr;
            }
            
            string base = strstack.top();
            strstack.pop();
            
            curr = base + repeat;
        }else {
            curr += c;
        }
    }
    
    cout << "Result: " << curr << endl;
    return 0;
}