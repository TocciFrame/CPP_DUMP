#include <algorithm>
using namespace std;

struct node {
	int elem;
	node* left;
	node* right;
	node* parent;

    int height(){
        return heightHelper(this) - 1;
    }
    
    int heightHelper(node* n) {
        if (!n){
            return 0;
        }
        
        int left = heightHelper(n->left);
        int right = heightHelper(n->right);
        return 1 + max(left, right);
    }

    int depth() {
        int dep = 0;
        node* curr = parent;
        
        while(curr){
            dep++;
            curr = curr->parent;
        }
        
        return dep;
    }
};