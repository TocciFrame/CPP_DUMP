#include <iostream>
#include <string>
using namespace std;

struct node {
	char ch;
	int weight;
	node *left, *right, *parent;

	node(char c, int w) : ch(c), weight(w), left(nullptr), right(nullptr), parent(nullptr) {};

	// TODO getCode
	string getCode() {
	    string code = "";
	    node* curr = this;
	    
	    while(curr->parent != nullptr) {
	        node* par = curr->parent;
	        
	        if (curr == par->left) {
	            code = "0" + code;
	        } else {
	            code = "1" + code;
	        }
	        
	        curr = par;
	    }
	    
	    return code;
	}
};